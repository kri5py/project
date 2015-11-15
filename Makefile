try: main.o TOH2.o nprnt.o tohsoln.o
	cc  main.o nprnt.o TOH2.o TOH2.h nprnt.h tohsoln.o -lm -lncurses -o abcd

main.o: main.c TOH2.h
	cc -Wall -c main.c
TOH2.o: TOH2.c TOH2.h
	cc -Wall -c TOH2.c
nprnt.o: nprnt.c nprnt.h
	cc -Wall -c nprnt.c
tohsoln.o: tohsoln.c 
	cc -Wall -c tohsoln.c



