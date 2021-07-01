#!/bin/bash
#this *.sh file is get the computer ip address
#Licence : http://github.com/Azabell1993

trap 'printf "\n";stop' 2

echo "======================================="
echo "---------------------------------------"
echo "github : http://github.com/Azabell1993 "
echo "---------------------------------------"
echo "======================================="
echo "------######---####\-------------------"
echo "--------##-----#--#|-------------------"
echo "--------##-----#--#|-------------------"
echo "--------##-----####/-------------------"
echo "--------##-----#-----------------------"
echo "--------##-----#-----------------------"
echo "------######--###----------------------"
echo "======================================="
printf "\n"
echo "-----streaming..........---------------"
printf "\n"

catch_name() {
	echo -n "USER NAME : "
	whoami > whoami.txt
	cat whoami.txt
	cat whoami.txt >> whoami_saved.txt
	printf "\n"
}

catch_ip()
{
	echo -n "Your computer IP : "
	printf "\n"
	ifconfig | grep 'inet ' > ip.txt
	cat ip.txt
	cat ip.txt >> ip_saved.txt
}

catch_name
catch_ip

