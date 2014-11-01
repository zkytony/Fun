#Makefile

FLAG = -Wall

all: matrix.o main.o main.out clean

matrix.o: matrix.cpp matrix.hpp
	g++ $(FLAG) -c matrix.cpp

main.o: main.cpp
	g++ $(FLAG) -c main.cpp

main.out: main.o matrix.o
	g++ $(FLAG) -o main.out main.cpp matrix.o

clean: 
	rm main.o
	rm matrix.o