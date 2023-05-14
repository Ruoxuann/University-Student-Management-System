#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h" 


class Student : public Person {
public:
    Student(std::string name, std::string email, int id, std::string passport, int mobile, std::string major, int grade);
    
private:
    /*    //在Person中定义吧？
    std::string name_;
    std::string email_;
    int id_;
    std::string passport_;
    int mobile_; 
    */

    std::vector<Course> courses_taken_;
    std::vector<Course> courses_chosen_;
    std::vector<double> marks_;  //这里假设分数是double类型了
    std::string major_;
    int grade_;
};

#endif
