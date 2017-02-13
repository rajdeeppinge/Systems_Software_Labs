#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    
    pid_t pid_a = getpid(), pid_e;
    char cmd[20];

    //two consecutive forks create 3 processes say c, d (children of a) and e(child of c)
    fork();
    fork();
    
    //now there are total 4 processes - 1 main, 2 child, 1 grandchild
    if(getppid() != pid_a)	//the only processes which does not have parent a is e, therefore we get e (since it is child of c)
	pid_e = getpid();	


    if(getpid() != pid_e || getpid() != pid_a)
	fork();			//we have four nodes, a, c, d, e of which we need children only for c and d therefore don't fork for a and e
//here f(child of c) and g(child of d) are created

	
    //since we need 1 more child for a we fork once
    if(getpid() == pid_a)
	fork();			//b is created (child of a)

    if(pid_a == getpid()) {
    	sprintf(cmd, "pstree -p %d\n", pid_a);
    	system(cmd);
    }
    else
	while(1);		//while loop to keep the processes running

    return 0;
}
