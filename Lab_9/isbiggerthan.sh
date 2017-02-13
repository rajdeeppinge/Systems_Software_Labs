#!/bin/bash

if [ $# -lt 2 ]
	then echo "$0: ERROR: Require path and size" 1>&2
	exit 2
fi
#re='^-?[0-9]+([.][0-9]+)?$'
#re='^[0-9]+$'
num=$1
if [ "$num" -eq "$num" ] #2>/dev/null
	then "none"
	
	else 	
	echo "$0: ERROR: Require a number for $1" #1>&2
	exit 3
fi
if [ $1 -lt 0 ]
	then echo "$0: ERROR: Require a positive number for $1" 1>&2
	exit 4
fi
if [ ! -e "$2" ]
	then echo "$0: ERROR: File $2 does not exist" 1>&2
	exit 5
fi
if [ -d "$2" ]
	then file_size=$(ls -s $2 | grep "total" | cut -d " " -f 2)
		if [ $file_size -gt $1 ]
			then echo "yes"
			exit 0
		else 
			echo "no"
			exit 1 

		fi
fi
if [ -e "$2" ] 
	 file_size1=$(ls -s $2 | cut -d " " -f 1)
		if [  $file_size1 -gt $1 ] || [ $file_size1 -eq $1 ]
			then echo "yes"
			exit 0
		else 
			echo "no"
			exit 1
		fi
fi
