#!/bin/bash

#####################################################################
#Script Name	:  game_install.sh                                  #
#Description	:  2021.06.02                                       #
#Args			:                                                   #
#Author			:                                                   #
#Email			: jeewoo19930315@gmail.com                          #
#Blog			: azabell.github.io                                 #
#####################################################################

start()
{
	printf "Mr/Ms. : "
	whoami
	
	whoami >> whoami.text
	echo "Hello! Nice to meet you!"
	cat whoami.text >> whoami_saved.text

	printf "\n"
	echo "Running the Makefile"
	make first
	make
}

catch_toplist()
{
	echo "saved toplist"

	printf "\n"
	printf "latest estimate User : "
	cat whoami.text

	printf "\n"

	cat toplist >> toplist_saevd.text

	echo "Open the toplist log"
	cat toplist_saevd.text 
}

start
catch_toplist
