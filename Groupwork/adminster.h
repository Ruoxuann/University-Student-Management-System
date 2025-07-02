#pragma once
#include <string>
#include <vector>
#include "Person.h"
#include "Course.h" 
#include<iostream>
#include<iomanip>
using namespace std;
class administer : public Person {
private:
	string title;
	string programme;
public:
	administer(string n = "haven't set", string t = "haven't set", string p = "haven't set") {
		name = n; title = t; programme = p;
	}
	void print() {
		cout << setw(15) << "Name" << setw(15) << "Title" << setw(15) << "Programme" << endl;
		cout << setw(15) << name << setw(15) << title << setw(15) << programme << endl;

	}


};