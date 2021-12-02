# eenvoudige makefile
all: hoofd.o koffiebord.o
	g++ -Wall -Wextra -o hetspel koffiebord.o koffiebord.o
koffiebord.o: koffiebord.cc koffiebord.h
	g++ -Wall -Wextra -c koffiebord.cc
hoofd.o: hoofd.cc koffiebord.h
	g++ -Wall -Wextra -c hoofd.cc
