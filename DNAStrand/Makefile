CC = g++
CFLAGS = -g -Wall
OBJECTS = bin/DNAStrandDriver.o bin/DNAStrand.o
CPP_VERSION=c++17

.PHONY: all clean valgrind tarball

all: bin bin/DNAStrandDriver

bin:
	mkdir -p bin

bin/DNAStrandDriver: ${OBJECTS}
	${CC} ${CFLAGS} -std=${CPP_VERSION} -o bin/DNAStrandDriver ${OBJECTS}

bin/DNAStrandDriver.o: src/DNAStrandDriver.cpp include/DNAStrand.h
	${CC} ${CFLAGS} -std=${CPP_VERSION} -o bin/DNAStrandDriver.o -c src/DNAStrandDriver.cpp

bin/DNAStrand.o:  src/DNAStrand.cpp include/DNAStrand.h
	${CC} ${CFLAGS} -std=${CPP_VERSION} -o bin/DNAStrand.o -c src/DNAStrand.cpp

runMe: bin/DNAStrandDriver
	bin/DNAStrandDriver

clean:
	rm -rf bin/DNAStrandDriver  ${OBJECTS}

valgrind:
		valgrind -v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./bin/DNAStrandDriver
	
tarball:
	tar czf ../DNAStrand.tar.gz ../DNAStrand