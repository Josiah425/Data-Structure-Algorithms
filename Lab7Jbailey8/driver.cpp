#include "Graph.h"
#include "course.h"
#include "Schedule.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

int main(int argc, char * argv[]){
    std::ifstream fin;
    std::string line;
    std::string buff;
    Graph graph;
    Schedule schedule;
    bool good = 1;
    int i = 0;
    if(argc != 4){
	exit(1);
    }
    //Requirement file
    fin.open(argv[1]);
    if(!fin.good()){
        std::cout << "Required file could not be found" << std::endl;
        exit(1);
    }
    //Get prereqs
    while(std::getline(fin, line)){
	std::stringstream ss(line);
	ss >> buff;
	if(buff == "COURSE"){
		ss >> buff;
		course * temp = new course(buff);
		Prereq * tempPre = temp->prereqs;
		while(ss >> buff){
			if(buff.size() == 1) {
				temp->letter = buff;
				continue;
			}
			if(temp->prereqs == NULL) {
				temp->prereqs = new Prereq;
				tempPre = temp->prereqs;
				tempPre->name = buff;
			}
			else{
				tempPre->next = new Prereq;
				tempPre = tempPre->next;
				tempPre->name = buff;
			}
		}
		graph.insertCourse(*temp);
	}
    }
    fin.close();

    fin.open(argv[2]);
    if(!fin.good()){
	std::cout << "Offerings file could not be found" << std::endl;
	exit(1);
    }
    fin.close();

    fin.open(argv[3]);
    //Offerings file doesn't matter for Lab7, skip to planned schedule
    if(!fin.good()){
        std::cout << "Planned Schedule file could not be found" << std::endl;
        exit(1);
    }
    //Check to see if the courses can be taken based on prereqs
    while(std::getline(fin, line)){
	std::stringstream ss(line);
	ss >> buff;
	while(ss >> buff){
		course * start = new course(buff);
		schedule.insertCourse(*start);
	}
    }
    /*graph.printGraph();
    schedule.printSchedule();*/
    if(!graph.checkSchedule(schedule)) {
		good = 0;
    }
    if(good){
        std::cout << "Good plan. Get to work." << std::endl;
    }

    fin.close();

    return 0;
}
