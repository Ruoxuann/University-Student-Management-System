#ifndef PERSON_H //0514 19:43 加
#define PERSON_H //0514 19:43 加

#pragma once
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Person
{
public:  //0514 19:43 hqy加的..
    Person(const std::string& name, const std::string& email, int id, const std::string& passport, int mobile)
        : name_(name), email_(email), id_(id), passport_(passport), mobile_(mobile) {}



private:
	string name, email, passport, mobile;
	int id;
	
};

#endif //0514 1943加
