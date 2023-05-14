#pragma once
#include "Person.h"
#include "Menu.h"
#include"Student.h"
#include"Course.h"
//#include <vector>


class MainProcess
{
private:
	Menu menu;
	Person* user_info;
	Student stu;
	vector<Student>stu_info;
	vector<Course>course_list;
	//Administrater ad;

public:
	bool login() {
		menu.UserType();
		cout << "Please choose user type, 1 for student, 2 for administrater, 3 for quit" << endl;
		int choice = this->inputInt();
		if (choice == 1) {
			user_info = &stu;
			while (this->SignUp());
		}
		else if (choice == 2) {
			//user_info = &ad;
			while (this->Ad_menu());
		}
		else if (choice==3) {
			return false;
		}
		return true;
	}
	bool SignUp() {
		menu.SignUp();
		//cout << "" << endl;
		return true;

	}

	bool Ad_menu() {
		//Menu.Ad_menu
		//cout << "1:add,2:search for mark; 3:delate,4.modify the mark, 5:check course choose" << endl;
		cout << "1.manage courses     2.manage students    3.quit" << endl;
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->manageCourse());
		}
		else if (choice == 2) {
			//while (this->manageStu());
		}
		else if (choice == 3) {
			return false;
		}
		return true;
	}
	bool manageCourse() {
		cout << "1:add,2:search for course; 3:delate 4.quit" << endl;
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->add());
		}
		else if (choice == 2) {
			while (this->searchCor());
		}
		else if (choice == 3) {
			while (this->delateCor());
		}
		else if (choice == 4) {
			return false;
		}
		return true;
	}
	
	bool add() {
		string c; string n; int g; string m;
		cout << "Course code: "; cin >> c;
		cout << "Course name: "; cin >> n;
		cout << "Enoroll grade: ";  g = this->inputInt();
		cout << "Enroll major: "; cin >> m;
		Course c1(c,n,g,m);
		course_list.push_back(c1);
		while (1) {
			cout << "Add another product (0: no, 1: yes) ? ";
			int addchoice = this->inputInt();
			if (addchoice == 1) {
				return true;
			}
			else if (addchoice == 0) {
				return false;
			}
			else {
				cout << "Please slect from 1 and 0!" << endl;
				//return true;
			}
		}
		return true;
	}

	bool searchCor() {
		cout << "Input code (input \"\*\"\ to list all products): ";
		string choice;
		cin >> choice;
		cout << "Code          Name          Enoroll grade          Enoroll major          " << endl;
		int found = 0;
		if (choice == "*") {
			for (int i = 0; i < course_list.size(); i++) {
				course_list[i].print(); found++;
			}
		}
		else {
			for (int i = 0; i < course_list.size(); i++) {
				if (course_list[i].getCode() == choice) {
					course_list[i].print(); found++;
				}
			}
		}
		if (found == 0) {
			cout << "No course found!" << endl;
		}
	
		return false;
	}
	bool delateCor() {
		cout << "Input the code ";
		string choice;
		cin >> choice;
		int found = 0;
		for (int i = 0; i < course_list.size(); i++){
			if (course_list[i].getCode() == choice){
				course_list.erase(course_list.begin() + i);
				i--;
				found++;
			}
		}
		if (found == 0) {
			cout << "No course found!" << endl;
		}
		return false;
	}

	int inputInt() {
		int i;
		while (!(cin >> i)) {
			cout << "This is not integer,please input again!" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		cin.clear();
		while (cin.get() != '\n');
		return i;
	}

};

