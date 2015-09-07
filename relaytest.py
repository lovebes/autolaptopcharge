import serial
import sys

ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=9600,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    timeout=0.1,
    xonxoff=0,
    rtscts=0,
    interCharTimeout=None
    )
ser.write('<'+sys.argv[1]+'>') #1 or 0
