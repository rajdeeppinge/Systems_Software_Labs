#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include<wait.h>

pid_t is_fork_valid() {
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }
    return pid;
}

/*void create_processes(int *leftchild, int i, int levels) {
    pid_t pid;
    if(i < levels) {
    
    printf("pid %d, ppid %d\n", getpid(), getppid());

    if( (pid=is_fork_valid()) == 0) {
        if(!*leftchild) {
            printf("pid %d created left child with pid %d\n", getppid(), getpid());
            *leftchild = 1;
        }

        else {
             printf("pid %d created right child with pid %d\n", getppid(), getpid());
        }
    }

    else if( (pid=is_fork_valid()) == 0) {
        if(!*leftchild) {
            printf("pid %d created left child with pid %d\n", getppid(), getpid());
        }

        else {
             printf("pid %d created right child with pid %d\n", getppid(), getpid());
             *leftchild = 0;
	}
	
    }

    create_processes(leftchild, ++i, levels);
    }
    else {
	*leftchild = 1;
    }
}*/

int main(/*int levels*/) {
    int i = 1, levels = 3, leftchild = 0;
    int process_id = 1;
    pid_t pid, stat;
    //create_processes(&leftchild, i, levels);

for(i = 1; i <= levels; i++) {
    printf("[%d] pid %d, ppid %d\n", process_id, getpid(), getppid());
    if(i < levels) {
    if(is_fork_valid() == 0) {
	process_id = process_id * 2;
	printf("[%d] pid %d created left child with pid %d\n",process_id, getppid(), getpid());
	continue;	
    }

    
//    else {
	if (is_fork_valid() == 0) {
	    process_id = process_id * 2 + 1;
	    printf("[%d] pid %d created right child with pid %d\n", process_id, getppid(), getpid());
	    continue;
	}
	
    	else {
	    wait(&stat);
	    printf("left child %d of %d exited with status %d\n", process_id, getpid(), stat);
	    wait(&stat)
            printf("right child %d of %d exited with status %d\n", process_id, getpid(), stat);
	    break;
	}
    }
}
    return 0;
}		
