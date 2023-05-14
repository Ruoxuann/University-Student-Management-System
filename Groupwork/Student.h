#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h" 
#include<iostream>
using namespace std;

class Student : public Person {
private:
    /*    //在Person中定义吧？
    std::string name_;
    std::string email_;
    int id_;
    std::string passport_;
    int mobile_;
    */

    vector<Course> courses_taken_;
    vector<Course> courses_chosen_;
    vector<double> marks_;  //这里假设分数是double类型了
    string major_;
    int grade_;

public:
    Student(int i = 0, string n = "", string m = "", string e = "",string major = "",int g=0) {
        id = i;
        name = n;
        mobile = m;
        email = e;
        //passpor?
        major_ = major;
        grade_ = g;
    }
    //Student(std::string name, std::string email, int id, std::string passport, int mobile, std::string major, int grade);
    
    void addCourse_taken(Course c) {
        courses_taken_.push_back(c);

    }

};

#endif
