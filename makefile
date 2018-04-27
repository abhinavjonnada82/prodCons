PRODCONS:main.o Buffer.o
		g++ -g -std=c++11 -o prodCons Buffer.o main.o -lpthread
main.o:Buffer.hpp main.cpp
		g++ -g -std=c++11 -c main.cpp -lpthread
Buffer.o:Buffer.hpp Buffer.cpp
		g++ -g -std=c++11 -c Buffer.cpp -lpthread

clean:
		rm -f *.o prodCons core
