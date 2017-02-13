#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    pid_t pid;
    char cmd[20];

    pid = getpid();    

    if (fork() == 0) {		//creating c (child of a)
	if (fork() == 0) {          //creating e (child of c)
            while(1);
	}
	if (fork() == 0) {          //creating f (child of c)
            while(1);
	}
	while(1);
    }

    //combination of two forks creates 3 processes 
    fork();			//creating d (child of a)

    //this fork is called by both a (main process) as well as d (which has been created in the above fork call) 
    fork();			//creating b(child of a), creating g (child of d)

    if (pid == getpid()) {	//this code must be executed only in main process
    	sprintf(cmd, "pstree -p %d\n", pid);
    	system(cmd);
    }
    else {			//if we are in some child process then go in infinite loop so that process is being executed and not terminated
    	while(1);
    }
    return 0;
}
