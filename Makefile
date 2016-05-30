CC = g++
CFLAGS  = -std=c++11 -g -Wall

fct: fct.o 
	$(CC) $(CFLAGS) fct.o -o fct

fct.o: fct.cpp
	$(CC) $(CFLAGS) -c fct.cpp

clean:
	rm -f *.o
	rm -f fct
