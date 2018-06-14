#include "prereqs.h"
#include "course.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char * argv[]){
    std::ifstream fin;
    std::string line;
    std::string buff;
    bool good = 1;

    //Requirement file
    if(!fin.open(argv[1]){
        std::cout << "Required file could not be found" << std::endl;
        exit(1);
    }
    //Get prereqs
    prereqs prerequisites(fin);
    fin.close();

    //Offerings file doesn't matter for Lab7, skip to planned schedule
    if(!fin.open(argv[3]){
        std::cout << "Planned Schedule file could not be found" << std::endl;
        exit(1);
    }
    //Check to see if the courses can be taken based on prereqs
    while(std::getline(fin, line)){
         if(!checkCourses(prerequisites, line)) good = 0;
    }
    if(good){
        std::cout << "Good plan. get to work." << std::endl;
    }


    return 0;
}
