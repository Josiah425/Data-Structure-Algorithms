all: driver

driver: driver.cpp course.o Graph.o Schedule.o
	g++ -g driver.cpp course.o Graph.o Schedule.o -o driver

course.o: course.cpp
	g++ -g -c course.cpp

Graph.o: Graph.cpp
	g++ -g -c Graph.cpp

Schedule.o: Schedule.cpp
	g++ -g -c Schedule.cpp

clean:
	rm -f *.o *~ driver
