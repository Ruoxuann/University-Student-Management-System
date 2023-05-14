#ifndef COURSE_H
#define COURSE_H

#include <string>
class Course {
public:
    Course(std::string code, std::string name, int grade_enroll, std::string major_enroll);

private:
    std::string code_;
    std::string name_;
    int grade_enroll_;
    std::string major_enroll_;
};

#endif
