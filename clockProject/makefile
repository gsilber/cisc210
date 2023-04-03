all: clock checkers

clock: FBCurses.o clock.o
	gcc FBCurses.o clock.o -o clock -lcurses
checkers: FBCurses.o checkers.o
	gcc FBCurses.o checkers.o -o checkers -lcurses
FBCurses.o: FBCurses.c FBCurses.h
	gcc -c FBCurses.c
clock.o: clock.c FBCurses.h
	gcc -c clock.c
checkers.o: checkers.c FBCurses.h
	gcc -c checkers.c
clean: dist
	rm -f clock checkers
dist:
	rm -f *.o