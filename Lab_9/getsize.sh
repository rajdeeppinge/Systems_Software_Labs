#!/bin/bash

if [ "$1" == "$var" ]
	then echo "ERROR: Require file" 1>&2

elif [ -d "$1" ]
	then echo -n "Size of directory is: "
		ls -s $1 | grep "total" | cut -d " " -f 2

elif [ -e "$1" ]
	then echo -n "Size of file is: "
     		ls -s $1 | cut -d " " -f 1

else
	echo "ERROR: File $1 does not exist" 1>&2

fi
