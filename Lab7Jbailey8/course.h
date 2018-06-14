#ifndef COURSE_H_
#define COURSE_H_

#include <iostream>
#include <string>

typedef struct Prereq{
	std::string name;
	Prereq *next;
} Prereq;

class course{
    public:
        struct Prereq *prereqs;
	course * next;
	std::string letter;
        std::string name;
	bool hasPrereqs;
	bool taken;
        course();
        course(std::string name);
	course(const course &name);
	void setPrereqs(course &name);
	course& operator=(const course &name);
	//~course();
};

#endif
