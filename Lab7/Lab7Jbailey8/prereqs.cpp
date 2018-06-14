#include "prereqs.h"
#include "course.h"
#include <string>
#include <sstream>

prereqs::prereqs(std::ifstream fin){
    std::string line;
    std::string buff;
    std::string temp;
    color = white;
    int i = 0;
    int k = 0;
    while(std::getline(fin, line)){
        std::stringstream ss(line);
        while(ss >> buff){
            if(buff == "COURSE"){
                ss >> buff;
                courses[i] = new course(buff);
                ss >> buff;
                int j = 0;
                while(ss >> buff){
                    courses[i]->adjlist[j] = new course(buff);
                    j++;
                }
                i++;
            }
            if(buff == "CHOOSE"){
                ss >> buff;
                std::string s1;
                int choose = atoi(buff);
                std::getline(ss, s1);
                chooseCourse[k] = new course(s1, choose);             
                k++;
            }
        }
    }
}

bool prereqs::checkCourses(std::string name){
    std::string buff;
    std::stringstream ss;
    int j = 0;
    ss >> buff;
    for(int i = 0; i < size; i++){
        
    }
}
