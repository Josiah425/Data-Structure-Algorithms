#ifndef GRAPH_H_
#define GRAPH_H_

#include "course.h"
#include "Schedule.h"

typedef struct TakenList{
	std::string name;
	TakenList * next;
} TakenList;

class Graph{
    public:
    	course * start;
	struct TakenList * takenList;
	Prereq * findPrereqs(std::string name);
    	Graph();
    	Graph(course *start);
    	bool getStart();
    	bool checkSchedule(Schedule sched);
	void insertTaken(std::string name);
	bool checkIfTakenPrereq(std::string name);
	bool checkCourse(course &name);
    	void insertCourse(course &name);
    	void printGraph();
	//~Graph();
};

#endif
