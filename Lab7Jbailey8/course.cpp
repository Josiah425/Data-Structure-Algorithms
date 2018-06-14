#include "course.h"

course::course(std::string name){
    this->name = name;
    this->next = NULL;
    this->prereqs = NULL;
    letter = "";
    hasPrereqs = false;
    taken = false;
}

course::course(const course &name){
	this->name = name.name;
	this->next = name.next;
	this->letter = name.letter;
	this->prereqs = name.prereqs;
	this->hasPrereqs = name.hasPrereqs;
	this->taken = name.taken;
}

course::course(){
    this->name = "";
    this->next = NULL;
    this->letter = "";
    this->prereqs = NULL;
    this->hasPrereqs = false;
    this->taken = false;
}

/*course::~course(){
	course * pos = this;
	course * temp;
	while(pos != NULL){
		Prereq * tempPre = pos->prereqs;
		Prereq * prevPre;
		while(tempPre != NULL){
			prevPre = tempPre->next;
			delete tempPre;
			tempPre = prevPre;
		}
		temp = pos->next;
		delete pos;
		pos = temp;
	}
}*/

void course::setPrereqs(course &name){
	Prereq * traverse = this->prereqs;
	while(traverse->next != NULL){
		traverse = traverse->next;
	}
	traverse->name = name.name;
	traverse->next = new Prereq;
}

course& course::operator=(const course &name){
	this->name = name.name;
	this->prereqs = name.prereqs;
	this->hasPrereqs = name.hasPrereqs;
	this->taken = name.taken;
}
