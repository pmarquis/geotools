DEBUG_LEVEL     = -g
EXTRA_CCFLAGS   = -std=c++11 -Wall
CXXFLAGS        = $(DEBUG_LEVEL) $(EXTRA_CCFLAGS)
CCFLAGS         = $(CXXFLAGS)
CC=g++
LDFLAGS=

INCPATH=./include
SRC=./src
EXEC=main

all: $(EXEC) 

main: haversine_distance.o main.o
	$(CC) -o main haversine_distance.o main.o $(LDFLAGS)

haversine_distance.o: $(SRC)/haversine_distance.cpp
	$(CC) -I $(INCPATH) -o haversine_distance.o -c $(SRC)/haversine_distance.cpp $(CCFLAGS)

main.o: $(SRC)/main.cpp include/haversine_distance.h 
	$(CC) -I $(INCPATH) -o main.o -c $(SRC)/main.cpp $(CCFLAGS)

clean_all: 
	rm -f *.o main
