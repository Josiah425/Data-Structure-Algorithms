# Here's the flag for C++11 support and a flag asking to be warned about
# everything.
#Shawn Bailey & Josiah Bailey
FLAGS = -Wall -std=c++11 -g

all: threeary

threeary: threeary.o driver.o
	g++ $(FLAGS) threeary.o driver.o -o driver

threeary.o: threeary.cpp threeary.h
	g++ $(FLAGS) -c threeary.cpp -o threeary.o

driver.o: driver.cpp threeary.h
	g++ $(FLAGS) -c driver.cpp -o driver.o

clean:
	rm -f *.o *~ driver
