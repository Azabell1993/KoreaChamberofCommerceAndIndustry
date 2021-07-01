#!/bin/bash

#####################################################################
#Script Name	: install.sh                                        #
#Description	:                                                   #
#Args			:                                                   #
#Author			:                                                   #
#Email			: jeewoo19930315@gmail.com                          #
#Blog			: azabell.github.io                                 #
#####################################################################

curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
cd bin/
sudo cp arduino-cli /bin/

arduino-cli

echo "--------------------------------------------------------------"
echo "-----------------------arduino-cli----------------------------"
echo "=============================================================="

echo "install the arduino-cli core install arduino:avr"

arduino-cli core install arduino:avr

echo "=============================================================="
echo "install finish the these program. you can use the arduino uno program"
echo "--------------------------------------------------------------"

echo "you can see information about connect the arduino board : "
arduino-cli board list


echo "  arduino-cli sketch new [skech name] "

echo "just compile : arduino-cli compile -b [Board type] [project name]"
echo "just upload : arduino-cli upload -p [port] -b [Board type] [project name]"

echo "good luck!"
