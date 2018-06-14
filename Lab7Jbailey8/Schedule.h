#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "course.h"

class Schedule{
	public:
		course * start;
		Schedule(course &name);
		Schedule();
		bool getStart();
		void insertCourse(course &name);
		void printSchedule();
		//~Schedule();
};

#endif
