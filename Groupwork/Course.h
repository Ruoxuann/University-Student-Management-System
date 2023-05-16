#ifndef COURSE_H
#define COURSE_H
#pragma once
#include <string>
#include<iostream>
using namespace std;
class Course {
private:
    string code_;
    string name_;
    int grade_enroll_;
    string major_enroll_;

public:
    Course(string code="", string name="", int grade_enroll=0, string major_enroll="") {
        code_ = code; name_ = name; grade_enroll_ = grade_enroll; major_enroll_ = major_enroll;
    }
    string getName() {
        return name_;
    }
    void print() {
        cout << code_ << "            " << name_ << "            " << grade_enroll_ << "            " << major_enroll_ << "            " << endl;
    }
    string getCode() {
        return code_;
    }
    int getGrade() {
        return grade_enroll_;
    }
    string getMajor() {
        return major_enroll_;
    }

};

#endif
