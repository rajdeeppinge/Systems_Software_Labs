#!/bin/bash

for arg in $*
do 
	if [ -e "$arg" ]
		then echo -n "$arg "
		     ls -s $arg | cut -d " " -f 1
	else 
		echo "$0: ERROR: File $arg does not exist" 1>&2
	fi
done
