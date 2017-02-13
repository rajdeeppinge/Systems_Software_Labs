CC=gcc -g

# Make everything
all: static_test shared_test

# Build the staticly-linked test program
static_test: static_test.c libtest.a
	$(CC) static_test.c -o static_test -L./ -ltest

# Build the dynamically-linked test program
shared_test: shared_test.c libtest.so
	$(CC) shared_test.c libtest.so -o shared_test 

# Build the static test library
libtest.a: libfile1.o libfile2.o
	ar rcs libtest.a libfile1.o libfile2.o

# Build the dynamic test library
libtest.so: libfile1.o libfile2.o
	$(CC) -shared -o libtest.so libfile1.o libfile2.o -Wl,-soname,libtest.so         

# Make an object file for the first library source file
libfile1.o: libfile1.c
	$(CC) -c libfile1.c

# Make an object file for the second library source file
libfile2.o: libfile2.c
	$(CC) -c libfile2.c

clean:
	rm -f *.o *.a *.so static_test
