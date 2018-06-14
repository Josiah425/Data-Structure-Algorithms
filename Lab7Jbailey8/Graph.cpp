#include "Graph.h"
#include "Schedule.h"
#include <string>
#include <sstream>

Graph::Graph(){
	this->start = new course();
	this->takenList = NULL;
}

Graph::Graph(course *start){
	this->start = start;
	this->takenList = NULL;
}

/*Graph::~Graph(){
	course * pos = this->start;
	course * temp;
	while(pos != NULL){
		temp = pos->next;
		delete pos;
		pos = temp;
	}
}*/

bool Graph::getStart(){
	if(this->start->name != "") return true;
	return false;
}

void Graph::insertCourse(course &name){
	course * traverse;
	if(!getStart()){
		this->start = &name;
		return;
	}
	for(traverse = this->start; traverse->next != NULL; traverse = traverse->next){
		
	}
	traverse->next = &name;
}

bool Graph::checkCourse(course &name){
	if(this->start == NULL) return false;
	course * traverseGraph;
	Prereq * prereqs = this->start->prereqs;
	for(traverseGraph = this->start; traverseGraph->next != NULL; traverseGraph = traverseGraph->next){
		prereqs = traverseGraph->prereqs;
		if(traverseGraph->name == name.name){
			while(prereqs != NULL){
				if(!checkIfTakenPrereq(prereqs->name)) return false;
				prereqs = prereqs->next;
			}
			traverseGraph->taken = true;
			name.taken = true;
			return true;
		}
	}
	if(traverseGraph->name == name.name){
		while(prereqs != NULL){
				if(!checkIfTakenPrereq(prereqs->name)) return false;
				prereqs = prereqs->next;
			}
			traverseGraph->taken = true;
			name.taken = true;
			return true;
	}
	this->insertCourse(name);
	traverseGraph->taken = true;
	name.taken = true;
	return true;
}

bool Graph::checkSchedule(Schedule sched){
    course * traverseSched;
    if(sched.start == NULL) return false;
    Prereq * travPre = sched.start->prereqs;
    bool returnVal = true;
    for(traverseSched = sched.start; traverseSched != NULL; traverseSched = traverseSched->next){
	if(!checkCourse(*traverseSched)) {
		travPre = traverseSched->prereqs;
		returnVal = false;
		break;
	}
	else{
		insertTaken(traverseSched->name);
	}
    }
    if(returnVal == false){
    	std::cout << "Bad plan. Here's why:" << std::endl;
	std::cout << "\t" << traverseSched->name << " Requires the prereqs: ";
	travPre = findPrereqs(traverseSched->name);
	while(travPre != NULL){
		std::cout << travPre->name << ' ';
		travPre = travPre->next;
	}
	std::cout << std::endl;
    }
    return returnVal;
}

void Graph::insertTaken(std::string name){
	TakenList * traverse;
	if(this->takenList == NULL){
		this->takenList = new TakenList;
		this->takenList->name = name;
		this->takenList->next = NULL;
		return;
	}
	for(traverse = this->takenList; traverse->next != NULL; traverse = traverse->next){
		
	}
	traverse->next = new TakenList;
	traverse->next->name = name;
}

bool Graph::checkIfTakenPrereq(std::string name){
	TakenList * traverse = this->takenList;
	while(traverse != NULL){
		if(traverse->name == name) return true;
		traverse = traverse->next;
	}
	return false;
}

Prereq * Graph::findPrereqs(std::string name){
	course * traverse = this->start;
	while(traverse->next != NULL){
		if(traverse->name == name){
			return traverse->prereqs;
		}
		traverse = traverse->next;
	}
	return traverse->prereqs;;
}

void Graph::printGraph(){
	course * traverse = this->start;
	Prereq * travPre = traverse->prereqs;
	while(traverse != NULL){
		std::cout << traverse->name << ' ';
		if(travPre != NULL) {
			std::cout << "Prereqs: ";
			while(travPre != NULL){
				std::cout << travPre->name << ' ';
				travPre = travPre->next;
			}
			std::cout << std::endl;
		}
		else{
			std::cout << std::endl;
		}
		traverse = traverse->next;
		if(traverse != NULL) travPre = traverse->prereqs;
	}
}
