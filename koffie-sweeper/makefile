# eenvoudige makefile
all: hoofd.o header.o
	g++ -Wall -Wextra -o hetspel header.o hoofd.o
header.o: header.cc header.h
	g++ -Wall -Wextra -c header.cc
hoofd.o: hoofd.cc header.h
	g++ -Wall -Wextra -c hoofd.cc
