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
		else if (choice == 3) {
			return false;
		}
		return true;
	}
	bool SignUp() {
		menu.SignUp();
		cout << " Please input your student ID: ";
		string id;
		cin >> id;
		int found = 0;
		if (id == "quit") {
			return false;
		}
		//Try to find the input id from the vector
		for (int i = 0; i < stu_info.size(); i++) {
			if (to_string(stu_info[i].getId()) == id) {
				found++; stu = stu_info[i];
				while (this->Stu_menu());
			}
		}
		//No id found
		if (found == 0) {
			cout << "Failed to find your student ID. Please input a new customer ID or input \" quit \" to move to parent menu: " << endl;
			return true;
		}
		return false;

	}

	bool Ad_menu() {
		//Menu.Ad_menu
		//cout << "1:add,2:search for mark; 3:delate,4.modify the mark, 5:check course choose" << endl;
		cout << "1.manage courses     2.manage students    3.manage mark     4.quit" << endl;
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->manageCourse());
		}
		else if (choice == 2) {
			while (this->manageStu());
		}
		else if (choice == 3) {
			//while(this->manageMar());
		}
		else if (choice == 4) {
			return false;
		}
		return true;
	}
	bool manageCourse() {
		cout << "1:add,2:search for course; 3:delate 4.quit" << endl;
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->addCor());
		}
		else if (choice == 2) {
			while (this->searchCor(course_list));
		}
		else if (choice == 3) {
			while (this->delateCor());
		}
		else if (choice == 4) {
			return false;
		}
		return true;
	}

	bool addCor() {
		string c; string n; int g; string m;
		cout << "Course code: "; cin >> c;
		cout << "Course name: "; cin >> n;
		cout << "Enoroll grade: ";  g = this->inputInt();
		cout << "Enroll major: "; cin >> m;
		Course c1(c, n, g, m);
		course_list.push_back(c1);
		while (1) {
			cout << "Add another course (0: no, 1: yes) ? ";
			int addchoice = this->inputInt();
			if (addchoice == 1) {
				return true;
			}
			else if (addchoice == 0) {
				return false;
			}
			else {
				cout << "Please slect from 1 and 0!" << endl;
			}
		}
		return true;
	}

	bool searchCor(vector<Course> c) {
		cout << "Input code (input \"*\" to list all products): ";
		string choice;
		cin >> choice;
		cout << "Code          Name          Enoroll grade          Enoroll major          " << endl;
		int found = 0;
		if (choice == "*") {
			for (int i = 0; i < c.size(); i++) {
				c[i].print(); found++;
			}
		}
		else {
			for (int i = 0; i < c.size(); i++) {
				if (c[i].getCode() == choice) {
					c[i].print(); found++;
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
		for (int i = 0; i < course_list.size(); i++) {
			if (course_list[i].getCode() == choice) {
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
	bool manageStu() {
		cout << "1:add infomation 2:search for student; 3:delate 4. quit" << endl;
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->addStu());
		}
		else if (choice == 2) {
			//while (this->searchStu());
		}
		else if (choice == 3) {
			//while (this->delateStu());
		}
		else if (choice == 4) {
			return false;
		}
		return true;
	}
	bool addStu() {
		int i; string n; int g; string m; string mo; string e;
		cout << "Student Id: "; i = this->inputInt();
		cout << "name: "; cin >> n;
		cout << "Grade: ";  g = this->inputInt();
		cout << "Major: "; cin >> m;
		cout << "Mobile: "; cin >> mo;
		cout << "Emile: "; cin >> e;
		Student s1(i, n, mo, e, m, g);
		stu_info.push_back(s1);
		while (1) {
			cout << "Add another student (0: no, 1: yes) ? ";
			int addchoice = this->inputInt();
			if (addchoice == 1) {
				return true;
			}
			else if (addchoice == 0) {
				return false;
			}
			else {
				cout << "Please slect from 1 and 0!" << endl;
			}
		}
		return true;
	}
	//bool searchStu(){}
	//bool deleteStu(){}

	bool manageMar() {
		//先输入并查找id，然后打印所有课程，输入code（push back到courses_taken_）。输入成绩（push back 到marks_)
		return false;
	}
	bool Stu_menu() {
		//选择界面
		cout << "1.choose course   2.query mark  3.view the chosen course 4.quit" << endl;
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->chooseCourse());
		}
		else if (choice == 2) {
			//while (this->manageStu());
		}
		else if (choice == 3) {
			while (this->searchCor(stu.getCourseChosen()));
		}
		else if (choice == 4) {
			return false;
		}
		return true;
	}
	bool chooseCourse() {
		cout << "Code          Name          Enoroll grade          Enoroll major          " << endl;
		for (int i = 0; i < course_list.size(); i++) {
			course_list[i].print();
		}
		cout << "Please choose the code from above: " << endl;
		string choice;
		cin >> choice;
		while (!this->CorIdCheck(choice,stu.getCourseChosen())) {
			cout << "You have chosen it, please choose another: ";
			cin >> choice;
		}
		int found = 0;
		for (int i = 0; i < course_list.size(); i++) {
			if (course_list[i].getCode() == choice) {
				found++;
				if (!(stu.getGrade() == course_list[i].getGrade())) {
					cout << "This course is not for your grade, please choose again!" << endl;
					return true;
				}
				else if (!(stu.getMajor() == course_list[i].getMajor())) {
					cout << "This course is not for your major,please choose again!" << endl;
					return true;
				}
				else {
					stu.addCourse_chosen(course_list[i]);
					cout << "Successfully chosen!" << endl;
					return false;
				}
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
	bool CorIdCheck(string code,vector<Course>c) {
		for (int i = 0; i < c.size(); i++) {
			if (code == c[i].getCode()) {
				//cout << "This code has been used,please input again!" << endl;
				return false;
			}
		}
		return true;
	}

};

