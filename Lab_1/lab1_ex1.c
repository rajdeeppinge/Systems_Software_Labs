#include<stdio.h>

union {
    int x;
    char c;
}u1;

int main() {
    u1.x = 1;

    if(u1.c == 1)
	printf("This is a Little Endian machine\n");
    else
	printf("This is a Big Endian machine\n");
	
    return 0;
}
