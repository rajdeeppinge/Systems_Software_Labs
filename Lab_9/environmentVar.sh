#!/bin/bash

echo "Path command: $PATH"
echo "Hello $USER!"
echo "Your current working directory is: $PWD"
echo "Your home directory is: $HOME"
echo "Shell command: $SHELL"

# Additional environment variables
echo "arg 0: $0"
echo "arg 1: $1"
echo "arg 2: $2"
echo "arg 3: $3"
echo "arg 4: $4"

# Use of $* and $#
echo "There are $# arguments to the script"
echo "Arguments not including the name of the script: $*"
