CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: integrate

integrate: integrate.o functions.o mathlib.o
	$(CC) -o integrate integrate.o functions.o mathlib.o

integrate.o: integrate.c
	$(CC) $(CFLAGS) -c integrate.c

mathlib.o: mathlib.c
	$(CC) $(CFLAGS) -c mathlib.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f integrate *.o

format:
	clang-format -i -style=file *.{c,h}

tst_all:
	./integrate -a -p 0 -q 1 -n 20
	./integrate -b -p 2 -q 3 -n 20
	./integrate -c -p -10 -q 10 -n 20
	./integrate -d -p -3.14 -q 3.14 -n 20
	./integrate -e -p -3.14 -q 3.14 -n 20
	./integrate -f -p 2 -q 10 -n 20
	./integrate -g -p -12.56637 -q 12.56637 -n 20
	./integrate -h -p 1 -q 10 -n 20
	./integrate -i -p 0 -q 1 -n 20
	./integrate -j -p 0 -q 3.14 -n 20
