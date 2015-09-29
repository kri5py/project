try: main.o TOH2.o
	cc main.o TOH2.o -o try
main.o: main.c TOH2.h
	cc -Wall -c main.c
TOH2.o: TOH2.c TOH2.h
	cc -Wall -c TOH2.c



