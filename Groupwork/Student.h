#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h" 
#include<iostream>
#include<iomanip>
using namespace std;
#pragma once
#endif


class Student : public Person {
private:

    vector<Course> courses_taken_;
    vector<Course> courses_chosen_;
    vector<double> marks_;
    string major_;
    int grade_;

public:
    Student(int i = 0, string n = "", string m = "", string e = "", string major = "", int g = 0) {
        id = i;
        name = n;
        mobile = m;
        email = e;
        //passpor?
        major_ = major;
        grade_ = g;
    }
    void addCourse_taken(Course c) {
        courses_taken_.push_back(c);
    }
    void addCourse_chosen(Course c) {
        courses_chosen_.push_back(c);
    }
    vector<Course> getCourseChosen() {
        return courses_chosen_;
    }
    vector<Course> getCourseTaken() {
        return courses_taken_;
    }
    vector<double>getMark() {
        return marks_;
    }
    void addMark(double m) {
        marks_.push_back(m);
    }
    int getGrade() {
        return grade_;
    }
    string getMajor() {
        return major_;
    }
    void print() {
        cout << setw(15) << "id" << setw(15) << "name" << setw(15) << "grade" << setw(15) << "major" << setw(15) << "mobile" << setw(15) << "email" << endl;
        cout << setw(15) << id << setw(15) << name << setw(15) << grade_ << setw(15) << major_ << setw(15) << mobile << setw(15) << email << endl;
    }
    void show() {
        cout << setw(15) << id << setw(15) << name << setw(15) << grade_ << setw(15) << major_ << setw(15) << mobile << setw(15) << email << endl;

    }

};


