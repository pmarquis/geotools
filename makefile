DEBUG_LEVEL	 = -g
EXTRA_CCFLAGS   = -std=c++11 -W -Wall -Werror
CXXFLAGS		= $(DEBUG_LEVEL) $(EXTRA_CCFLAGS)
CCFLAGS		 = $(CXXFLAGS)
CC=g++
LDFLAGS=

INCPATH=./include
SRC=./src
TEST=./tests
EXEC=main
TEST_EXEC=test


clean_all: 
	rm -f *.o main test

all: $(EXEC) $(TEST_EXEC)

main: haversine_distance.o main.o
	$(CC) -o main haversine_distance.o main.o $(LDFLAGS)

haversine_distance.o: $(SRC)/haversine_distance.cpp
	$(CC) -I $(INCPATH) -o haversine_distance.o -c $(SRC)/haversine_distance.cpp $(CCFLAGS)

main.o: $(SRC)/main.cpp include/haversine_distance.h 
	$(CC) -I $(INCPATH) -o main.o -c $(SRC)/main.cpp $(CCFLAGS)

test: haversine_distance.o TestHaversineDistance.o test.o
	$(CC) -o test test.o haversine_distance.o TestHaversineDistance.o $(LDFLAGS) 

test.o:
	$(CC) -I $(INCPATH) -o test.o -c $(TEST)/test.cpp $(CCFLAGS) 

TestHaversineDistance.o:
	$(CC) -I $(INCPATH) -o TestHaversineDistance.o -c $(TEST)/TestHaversineDistance.cpp $(CCFLAGS) 

