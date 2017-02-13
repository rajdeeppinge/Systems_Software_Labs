#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int p1[2], p2[2], p3[2], p4[2];
    pid_t pid1, pid2, pid3, ppid;
    char buffer[100];
    int nbytes;


    ppid = getpid();

    if( pipe(p1) < 0 || pipe(p2) < 0 || pipe(p3) < 0 || pipe(p4) < 0 ) {
	exit(1);
    }

    if( (pid1 = fork()) == 0 && ppid == getppid() ) {
	//closing pipes which are not required
	close(p1[1]);          
        close(p2[0]); close(p2[1]);
        close(p3[0]); close(p3[1]);
        close(p4[0]); close(p4[1]);

	while ( (nbytes = read(p1[0], buffer, 100)) > 0) {
      	    printf("+ Sent message along Pipe P1.\n");
	    printf("Child 1 read: %s. ", buffer);
	}

   	printf("C1 exiting...\n");
	exit(0);
    }

    if( (pid2 = fork()) == 0 && ppid == getppid() ) {
	close(p1[1]); close(p1[1]);
        close(p2[1]);
        close(p3[0]);
        close(p4[1]); 

	while ( (nbytes = read(p2[0], buffer, 100)) > 0) {
            printf("+ Sent message along Pipe P2.\n");
	    int k = 0;
	  /*  while(*(buffer + k) != '\0') {
		k++;
	    }*/
	    if( buffer[0] == '2') {
            	printf("Child 2 read: %s. ", (buffer+1));
	    }
	    else {
		printf("* Forwarding message along Pipe P3.");
		write(p3[1], buffer+1, 100);
//		printf("* Forwarding message along Pipe P3.");
	    }
        }

	       close(p3[1]);


	while ( (nbytes = read(p4[0], buffer, 100)) > 0)
            printf("Child 2 read: %s. ", buffer);

	close(p2[0]); 
//	close(p3[1]);
        close(p4[0]);

	printf("C2 exiting...\n");
        exit(0);

    
    }

    if( (pid3 = fork()) == 0 && ppid == getppid() ) {
	close(p1[1]); close(p1[1]);
        close(p2[1]);
        close(p3[1]);
        close(p4[0]);

	while ( (nbytes = read(p2[0], buffer, 100) > 0) ) {
            printf("+ Sent message along Pipe P2.\n");
            int k = 0;
  /*          while(*(buffer + k) != 0) {
                k++;
            }*/
            if(buffer[0] == '3') {
                printf("Child 3 read: %s. ", (buffer+1));
            }
            else {
		printf("* Forwarding message along Pipe P4.");
                write(p4[1], buffer+1, 100);
//                printf("* Forwarding message along Pipe P4.");
            }
        }

//	close(p2[0]);
//        close(p3[0]);
        close(p4[1]);


        while ( (nbytes = read(p3[0], buffer, 100)) > 0) {
            printf("Child 3 read: %s. ", buffer+1);
        }

	close(p2[0]); 
        close(p3[0]);
//        close(p4[1]);
	        printf("C3 exiting...\n");

        exit(0);
    }

    if( pid1!=0 && pid2!=0 && pid3!=0) {	//means it is in parent
	
	// parent does not need these pipes;
	close(p1[0]); 
        close(p2[0]);
        close(p3[0]); close(p3[1]);
	close(p4[0]); close(p4[1]);
	

	int numMsg, i, j=0, childNum, status;
	char msg[100] ;

	printf("- Hello, I am the parent. How many messages should I send? ");
	scanf("%d", &numMsg);

	for(i = 1; i<= numMsg; i++) {
	    
	    char m[100], m1[100];

	    sleep(1);
	    printf("- Message %d (<msg> <child>): ", i);
	    scanf("%s %d", msg, &childNum);

//	    printf("%s\n", msg);
//	    printf("%d\n", childNum);    

	    if(childNum == 1) {
		write(p1[1], msg, 100);    
	    }
	    
	    if(childNum == 2 || childNum == 3) {
		if(childNum == 2) {
		    strcat(m, "2");
		    strcat(m, msg);
			                write(p2[1], m, 100); 
		}
		else { 
		    strcat(m1, "3");
		    strcat(m1, msg);
		
                    write(p2[1], m1, 100);
		}
            }

	}

	sleep(2);

	close(p1[1]);
	close(p2[1]);

//	waitpid(pid1, &status, 0);
    }

    printf("parent exit\n");
    return 0;
}
