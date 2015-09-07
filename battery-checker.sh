#!/bin/bash

xfce4-terminal -e "tail -f /dev/ttyUSB0"  #depending on your Linux distro, change accordningly to your terminal emulator

while [[ true ]];
do
  sleep 1
  cap=`cat /sys/class/power_supply/BAT0/capacity`
  status=`cat /sys/class/power_supply/BAT0/status`
  clear
  tput cup 6 5
  echo "Observing battery: capacity is $cap, status is $status"
  chargeflag=`echo "$cap < 15" | bc`
  if [ $status == "Full" ];
  then
    #mplayer ~/bin/batterydone.mp3
    #mplayer ~/bin/batterydone.mp3
    python ~/bin/relaytest.py 0
  elif [ $status == "Charging" ];
  then
    tput cup 6 5
    echo "Observing battery: capacity is $cap, status is $status"
  elif (( $chargeflag ));
  then
    #mplayer ~/bin/chargebattery.mp3
    #mplayer ~/bin/chargebattery.mp3
    python ~/bin/relaytest.py 1
  fi
  

done

#will eventually communicate with Arduino serial port to turn on/off the relay that will manage the adapter plug!!!!
