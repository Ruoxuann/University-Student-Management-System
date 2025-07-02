#ifndef PERSON_H 
#define PERSON_H 

#pragma once
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Person
{
protected:
	string name, email, mobile;
	int id;

public:


	int getId() {
		return id;
	}
	virtual void print() {
		cout << "Name: " << name << endl;
		cout << "Email: " << email << endl;
		cout << "Mobile" << mobile << endl;
	}

};

#endif 
