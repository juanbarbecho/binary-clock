CC = cc
CFLAGS = -Wall
LDFLAGS = -lncurses

all: clock

clock: main.o display.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c display.h
	$(CC) -c $(CFLAGS) $<

display.o: display.c display.h
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	rm -f *.o clock
run:
	./clock.sh | ./clock
