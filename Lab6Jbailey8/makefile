# Here's the flag for C++11 support and a flag asking to be warned about
# everything. 
#Josiah Bailey & Shawn Bailey
FLAGS = -Wall -std=c++11 -g

all: BST

BST: BST.o driver.o
	g++ $(FLAGS) BST.o driver.o -o driver

BST.o: BST.cpp BST.h
	g++ $(FLAGS) -c BST.cpp -o BST.o

driver.o: driver.cpp BST.h
	g++ $(FLAGS) -c driver.cpp -o driver.o

clean:
	rm -f *.o *~ driver
