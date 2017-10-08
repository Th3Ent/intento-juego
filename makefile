all: main-auto.cpp camino.cpp ciudad.cpp

#all: main-nor.cpp camino.cpp ciudad.cpp


CXX=g++
CXXFLAGS= -std=c++11  -g
CXXFINALFLAG = -fpermissive -lncurses

OBJS = main.o camino.o ciudad.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o game ${OBJS} ${CXXFINALFLAG} 

clean:
	rm -rf *.o game
	
	