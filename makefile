all: calul

calul: calul.c
	gcc -o calul calul.c

clean:
	rm -f calul.o