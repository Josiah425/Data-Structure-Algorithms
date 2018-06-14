#include "course.h"
#include <fstream>;

class prereqs{
    course * courses;
    course * chooseCourse;
    prereqs(course currCourse, std::ifstream fin);
    bool checkCourses(std::string name);
};
