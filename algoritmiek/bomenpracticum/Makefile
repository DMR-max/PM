# eenvoudige makefile
all: boomtester.o boom.o knoop.o beeldbuffer.o
	g++ -Wall -std=c++11 -o bomenpracticum boomtester.o boom.o knoop.o beeldbuffer.o
boomtester.o: boomtester.cc boom.h beeldbuffer.h
	g++ -Wall -std=c++11 -c boomtester.cc
boom.o: boom.cc beeldbuffer.h
	g++ -Wall -std=c++11 -c boom.cc
knoop.o: knoop.cc knoop.h
	g++ -Wall -std=c++11 -c knoop.cc
beeldbuffer.o: beeldbuffer.cc beeldbuffer.h
	g++ -Wall -std=c++11 -c beeldbuffer.cc
