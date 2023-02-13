all: test2

test2: test2.o program2.o
	g++ -o test2 test2.o program2.o

test2.o: test2.cpp
	g++ -c test2.cpp

program2.o: program2.cpp
	g++ -c program2.cpp

clean:
	rm -f test2 *.o

run: test2
	./test2
