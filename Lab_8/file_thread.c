#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

void *file_line_count(void *args) {
    int lineCount = 0;

    char *filename = (char *) args;
    int fd = open(filename, O_RDONLY);

    if(fd == -1) {
	printf("file open failed\n");
	pthread_exit(NULL);
    }

    char buf;

//    printf("%d\n", lineCount);

    while(read(fd, &buf, 1) != '\0') {
	if( buf == '\n')
	    lineCount++;	
    }

    printf("File: %s contains: %d lines\n", filename, lineCount);
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {

    if (argc <= 1) {
        printf("Enter the NOOFFiles, names of files\n");
        exit(0);
    }

//    int *noOfFiles = argv[1];
//    printf("no = %d\n", *noOfFiles);
    pthread_t threads[argc-1];

    int i;

    for(i = 0; i<argc-1; i++) {
	pthread_create(&threads[i], NULL, file_line_count, argv[i+1]);
//	printf("%s\n", argv[i+1]);
    }

    for (i = 0; i < argc-1; i++) {
    /* Make call to pthread_join here */
	pthread_join(threads[i], NULL);
    }

    pthread_exit (NULL);
}
