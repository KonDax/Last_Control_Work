all : main.o sorts.o arraywork.o
	g++ main.o sorts.o arraywork.o

main.o : main.c
	g++ -c main.c

sorts.o : sorts.c
	g++ -c sorts.c

arraywork.o : arraywork.c
	g++ -c arraywork.c

clean : 
	rm - rf *.o a.out
