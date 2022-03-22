load:load.c
	gcc -c -O3 load.c
	gcc -o load load.o
all:load

clean:
	rm -f load *.o books.dat

