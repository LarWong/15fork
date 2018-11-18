all: fork.o
	gcc -o driver fork.o
fork.o: fork.c
	gcc -c fork.c
run:
	./driver
clean:
	rm -f driver *.o *~ *.swp
