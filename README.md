# autolaptopcharge

YEAH! pull me baby


Clicking the image will move to the youtube video. If you want to see it, open in another tab.
[![ScreenShot](http://img.youtube.com/vi/JI8ckyB9A28/0.jpg)](http://youtu.be/JI8ckyB9A28)

Cautious conduct in using laptop has led to the need for charging only when needed, in order to use its lithium battery for as long as possible.

While it is known that modern batteries and chargers are known to stop charging when battery is full, I have a tendency to not trust these claims, especially when I can't find any documents supporting it.

So, for my trustworthy, traveler-prone sub laptop, Acer C720 Chrooomebook, I knew I had to build one. 

Parts needed were:
Basic Arduino Uno

4-in-1 Relay board (only need one relay on that board)

Some wires to connect

Acer C720 needs to run crouton or Ubuntu or just any Linux 

Python needs to be run, with pyserial installed

Linux needs to run bash

Multi-outlet or any other spare extension cord you can cut to splice into the relay (middle hole and the left hole, if looking at the holes)


1) Arduino needs to be set up(ie. loaded) with the sketch at GitHub.

2) A way to get batter state. In my particular laptop (Acer C720 on Crouton), this is how: 

cat /sys/class/power_supply/BAT0/capacity

cat /sys/class/power_supply/BAT0/status

3) Download the files to ~/bin folder: battery-checker.sh, relaytest.py

4) Edit the python file if the serial port to Arduino is different from /dev/ttyUSB0

5) Check arduino-python communication by running : 'python ~/bin/relaytest.py 1' (which turns relay on)

6) All set, run the batttery-checker.sh (need to run 'chmod +x ~/bin/battery-checker.sh' first), which will open two terminal windows. One is needed to suck out all the serial buffer stream Arduino is spitting out to the laptop... for some reason the script won't run without getting that out.

7) Arrange the charger and multi-outlet as seen in video

8) Now you don't have to touch the adapter ever, knowing in full confidence that it will start charging at 15%, and stop charging at 100%!!!

