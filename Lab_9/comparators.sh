#!/bin/bash

#string
var=amit
if [ "$1" = "$var" ] ; then echo "string $1 equals $var" ; fi
if [ "$1" == "$var" ] ; then echo "string $1 equals $var" ; fi
if [ "$1" != "$var" ] ; then echo "string $1 does not equals $var" ; fi
if [ -z $var ] ; then echo "string $var is empty!"; fi
if [ -n $var ] ; then echo "string $var is not empty!"; fi

#numeric
a=1
l=1
if [ $a -eq $l ] ; then echo "number $l equals $a" ; fi
if [ $a -ne $l ] ; then echo "number $l does not equal $a" ; fi
if [ $a -gt $l ] ; then echo "$a is greater than $l" ; fi
if [ $a -lt $l ] ; then echo "$a is less than $l" ; fi

#file/dir properties
if [ -d "$PWD" ] ; then echo "$PWD exists and is a directory!" ; fi
if [ -e "$PWD" ] ; then echo "$PWD exists!" ; fi
if [ -f "$1" ] ; then echo "$1 exists and is not a directory!" ; fi
if [ -r "$PWD" ] ; then echo "$1 exists and is readable!" ; fi
if [ -s "$HOME" ] ; then echo "$1 exists and has size greater than zero!" ; fi
if [ -w "$HOME" ] ; then echo "$1 exists and is writable!" ; fi
if [ -x "$HOME" ] ; then echo "$1 exists and is executable!" ; fi
# NOTE: Since everything's on the same line, you need ;s (semicolon's) between
# the if and the then and between the then and the fi
