all: stupid.c
	gcc stupid.c

run:
	./a.out

clean:
	rm a.out | rm why.txt
