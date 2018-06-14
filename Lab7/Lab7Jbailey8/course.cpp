#include "course.h"

course::course(std::string name){
    this->name = name;
    this->adjlist = NULL;
    this->seriesCourses = NULL;
    choose = -1;
}
course::course(std::string name, int choose){
    std::stringstream ss(name);
    std::string buff;
    this->name = "series of courses";
    this->choose = choose;
    this->adjlist = NULL;
    while(ss >> buff){
        this->seriesCourses = new course(buff);
    }
}
