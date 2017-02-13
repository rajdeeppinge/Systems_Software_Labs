#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {

    pid_t pid;
    char cmd[20];

    pid = getpid();             //storing pid of main process   

    if (fork() == 0) {          //b is created (child of a)
        while(1);
    }

    if (fork() == 0) {          //creating c (child of a)
        if (fork() == 0) {      //creating e (child of c)
            while(1);
        }
        if (fork() == 0) {      //creating f (child of c)
            while(1);
        }
        while(1);
    }

    if (fork() == 0) {          //creating d (child of a)
        if (fork() == 0) {      //creating g (child of d)
            while(1);
        }
        while(1);
    }

    sprintf(cmd, "pstree -p %d\n", pid);
    system(cmd);
    return 0;
}

