CC = g++
CXXFLAGS += -Wall
CXXFLAGS += -std=c++11
DIR = `basename $(CURDIR)`

all: main
	./main

main: main.o
	$(CC) $(CXXFLAGS) main.o -o main

main.o: main.cpp setSimple.hpp
	$(CC) $(CXXFLAGS) -c  main.cpp

# singlelist.o: singlelist.cpp singlelist.h
# 	$(CC) $(CXXFLAGS) -c singlelist.cpp

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

zip: clean
	( cd ../; zip -r $(DIR).zip $(DIR) )


clean:
	rm -f *.o main