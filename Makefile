CC      := gcc
CFLAGS  := -std=c99 -Wall -Wextra -O2
LDFLAGS :=

.PHONY: all clean run1 run2 run3

all: prog1 prog2 my3proc

prog1: main.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

prog2: main2.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

my3proc: main3.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

run1: prog1
	./prog1

run2: prog2
	./prog2

run3: my3proc
	./my3proc

clean:
	rm -f prog1 prog2 my3proc *.o