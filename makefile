all: newmain.cpp camino.cpp ciudad.cpp
#all: main-nor.cpp camino.cpp ciudad.cpp


CXX=g++
CXXFLAGS= -std=c++11  -g
CXXFINALFLAG = -fpermissive -lncurses

OBJS = newmain.o camino.o ciudad.o
#OBJS = main-nor.o camino.o ciudad.o


all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o IA ${OBJS} ${CXXFINALFLAG} 

clean:
	rm -rf *.o IA
	
