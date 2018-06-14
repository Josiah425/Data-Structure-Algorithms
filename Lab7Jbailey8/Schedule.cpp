#include "Schedule.h"
#include "course.h"

Schedule::Schedule(course &name){
	this->start = &name;
}

Schedule::Schedule(){
	this->start = new course();
}

/*Schedule::~Schedule(){
	course * pos = this->start;
	course * temp;
	while(pos != NULL){
		temp = pos->next;
		delete pos;
		pos = temp;
	}
}*/

bool Schedule::getStart(){
	if(this->start->name != "") return true;
	return false;
}

void Schedule::insertCourse(course &name){
	course * traverse;
	if(!getStart()){
		this->start = &name;
		return;
	}
	for(traverse = this->start; traverse->next != NULL; traverse = traverse->next){
		
	}
	traverse->next = &name;
}

void Schedule::printSchedule(){
	course * traverse = this->start;
	while(traverse != NULL){
		std::cout << traverse->name << std::endl;
		traverse = traverse->next;
	}
}

