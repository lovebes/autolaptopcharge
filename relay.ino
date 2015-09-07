/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int relayswitch = 7;
int msg = 0;
int ledArr[] = {13,12,11,10,9};
int LED_SIZE = 5;

const byte numChars = 32;
char command[numChars];	// an array to store the received data
boolean newData = false;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(relayswitch, OUTPUT);     
  for (int i=0;i<LED_SIZE;i++){
    pinMode(ledArr[i], OUTPUT);
    digitalWrite(ledArr[i], HIGH);
  }
  Serial.begin(9600);
  msg = 0;
  clrCommand();
  analogWrite(relayswitch, 255); 
  Serial.println("ready!");
}

// the loop routine runs over and over again forever:
void loop() {
    readCommand();
//    showNewData();
    if(newData){
       Serial.print("command: ");    
       Serial.println(command);
       parseCommand();
   
    }
  
  
}

void clrCommand(){
  int i;
  for (i = 0; i < numChars; i++){
    command[i]=' ';
  }
}


int readCommand(){
	static boolean recvInProgress = false;
	static byte ndx = 0;
	char startMarker = '<';
	char endMarker = '>';
	char rc;
	

        while (Serial.available() > 0 && newData == false) {
		rc = Serial.read();

		if (recvInProgress == true) {
			if (rc != endMarker) {
				command[ndx] = rc;
				ndx++;
				if (ndx >= numChars) {
					ndx = numChars - 1;
				}
			}
			else {
				command[ndx] = '\0'; // terminate the string
				recvInProgress = false;
				ndx = 0;
				newData = true;
			}
		}

		else if (rc == startMarker) {
			recvInProgress = true;
		}
	}
  
}


void parseCommand()
{


      if ( strcmp(command, "1") == 0){
        msg = 1;
      }
      else if ( strcmp(command, "0") == 0){
        msg = 0;
      }
      else{
        msg = 0;

      }
      
      //process based on above parsing      
      if (msg == 1) {
        Serial.println("onRelay");
        analogWrite(relayswitch, 0);//why???
        // turn the LED on (HIGH is the voltage level)

      }
      if (msg == 0) {
        Serial.println("offRelay");        
        analogWrite(relayswitch, 255);  

      }
      ledArrFuc(msg);

      Serial.println("doneParsing");
      clrCommand();
      newData = false;
}


void ledArrFuc(int s){
  switch(s){
      case 1:
        for (int i=0;i<LED_SIZE;i++){
          digitalWrite(ledArr[i], HIGH);
        }      
        break;
      case 0:
        for (int i=0;i<LED_SIZE;i++){
          digitalWrite(ledArr[i], LOW);
        }           
        break;
      default:
        break;
  }

}


void showNewData() {
	if (newData == true) {
		Serial.print("This just in ... ");
		Serial.println(command);
		newData = false;
	}
}
