FLAGS=-lsfml-window -lsfml-system -lsfml-graphics -lpthread -std=c++17 -lm -O3

all: build/app

build/app:\
		tmp/main.o
	g++ tmp/main.o\
		-o build/app $(FLAGS)

tmp/main.o: main.cpp build/f
	g++ -c main.cpp -o tmp/main.o $(FLAGS)

build/f: 
	mkdir tmp -p
	mkdir build -p
	touch build/f
