#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

    pid_t pid_a, pid_c, pid_e;
    char cmd[20];

    pid_a = getpid();

    fork();			// creating c (child of a)
    
    if(getpid() != pid_a)	//after 1st fork either it is back in a or is in c. If not a then it must be c. Save pid of c
        pid_c = getpid();

    fork();			//creates children d(child of a) and e(child of c)
    
    if(getppid() == pid_c)	//if parent is c, we are at e and we don't want its child
        pid_e = getpid();	//save pid of e
    
    if(getpid() != pid_e)
        fork();			//we have four nodes a, c, d, e of which we need children for a, c and d only. therefore if it is e, we don't fork otherwise we fork.

    if(pid_a == getpid()) {
    	sprintf(cmd, "pstree -p %d\n", pid_a);
    	system(cmd);
    }
    else
	while(1);

    return 0;
}

