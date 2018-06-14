class course{
    public:
        std::string name;
        course * adjlist;
        course * seriesCourses;
        course(std::string name);
        course(std::string name, int choose);
        int choose;
};
