#include<stdio.h>

union u {
    int x;
    char c;
};

int main() {
    union u u1;
    u1.x = 1;

    if(u1.c == 1) {
	printf("The machine is little endian\n");
    }
    else {
	printf("The machine is big endian\n");
    }

    return 0;
}
