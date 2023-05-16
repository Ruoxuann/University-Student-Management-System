#ifndef PERSON_H //0514 19:43 加
#define PERSON_H //0514 19:43 加

#pragma once
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Person
{
protected:
	string name, email, passport, mobile;
	int id;

public:  
	
	//0514 19:43 hqy加的..
   /* Person(const std::string& name, const std::string& email, int id, const std::string& passport, const std::string& mobile)
        : name(name), email(email), id(id), passport(passport), mobile(mobile) {}*/

	int getId() {
		return id;
	}




	
};

#endif //0514 1943加
