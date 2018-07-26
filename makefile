OBJFILES = ${wildcard *.cpp}
all:
	g++ -std=c++11 ${OBJFILES} -o main
	./main
clear: 
	rm -rf *.o