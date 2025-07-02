#pragma once
#include "Person.h"
#include "Menu.h"
#include"Student.h"
#include"Course.h"
#include"adminster.h"


class MainProcess
{
private:
	Menu menu;
	Person* user_info;
	Student stu;
	vector<Student>stu_info;
	vector<Course>course_list;
	administer ad;

public:
	bool login() {
		menu.UserType();
		int choice = this->inputInt();
		if (choice == 1) {
			user_info = &stu;
			while (this->SignUp());
		}
		else if (choice == 2) {
			user_info = &ad;
			while (this->Ad_menu());
		}
		else if (choice == 3) {
			return false;
		}
		return true;
	}
	bool SignUp() {
		cout << "Please input your student ID : ";
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
	//The menu for administrator to choose function
	bool Ad_menu() {
		menu.Ad_menu();
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->manageCourse());
		}
		else if (choice == 2) {
			while (this->manageStu());
		}
		else if (choice == 3) {
			while (this->manageMar());
		}
		else if (choice == 4) {
			while (this->setAdInfo());
		}
		else if (choice == 5) {
			while (this->viewMyinfo());
		}
		else if (choice == 6) {
			return false;
		}
		return true;
	}
	//Set administrator information
	bool setAdInfo() {
		cout << "Please into your name: ";
		string n;
		getline(cin, n);
		cout << "Please into the programme you are in: ";
		string p;
		getline(cin, p);
		cout << "Please into the programme your title: ";
		string t;
		getline(cin, t);
		ad = administer(n, t, p);
		return false;
	}
	bool manageCourse() {
		menu.manageCourse();
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
			while (this->modifyCor());
		}
		else if (choice == 5) {
			return false;
		}
		return true;
	}
	//Add information for a course
	bool addCor() {
		string c; string n; int g; string m;
		cout << "Course code: ";  cin >> c;
		//Check repitation code
		while (!this->CorIdCheck(c, course_list)) {
			cout << "You have add it, please add another: ";
			cin >> c;
		}
		cout << "Course name: ";  cin >> n;
		//check reppitatiob for name
		while (this->CorNameReapeat(n)) {
			cout << "You have add it, please add another: ";
			cin >> n;
		}
		cout << "Enoroll grade: ";  g = this->inputInt();
		cout << "Enroll major: ";  cin >> m;
		//Creat the object
		Course c1(c, n, g, m);
		//Store it to the vector
		course_list.push_back(c1);
		//Ask whether to add another course
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
		cout << "Input code (input \"*\" to list all course): ";
		string choice;
		cin >> choice;
		cout << setw(15) << "Code" << setw(15) << "Name" << setw(15) << "Enoroll grade" << setw(15) << "Enoroll major" << endl;
		int found = 0;//Whether the input can be found
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
		cout << "Input the code: ";
		string choice;
		cin >> choice;
		int found = 0;
		for (int i = 0; i < course_list.size(); i++) {
			if (course_list[i].getCode() == choice) {
				course_list.erase(course_list.begin() + i);//find and delete the require course
				i--;
				cout << "Delete succefully!" << endl;
				found++;
			}
		}
		if (found == 0) {
			cout << "No course found!" << endl;
		}
		return false;
	}
	bool modifyCor() {
		//Delete the information first and then add a new one
		cout << "Input the code: ";
		string choice;
		cin >> choice;
		int found = 0;
		for (int i = 0; i < course_list.size(); i++) {
			if (course_list[i].getCode() == choice) {
				course_list.erase(course_list.begin() + i);
				i--;
				cout << "Delete succefully!" << endl;
				found++;
			}
		}
		if (found == 0) {
			cout << "No course found!" << endl; return false;
		}
		else {
			cout << "Please add the new infomation." << endl;
			while (this->addCor());
		}
		return false;

	}
	bool manageStu() {
		menu.manageStu();
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->addStu());
		}
		else if (choice == 2) {
			while (this->searchStu());
		}
		else if (choice == 3) {
			while (this->deleteStu());
		}
		else if (choice == 4) {
			while (this->modifyStu());
		}
		else if (choice == 5) {
			return false;
		}
		return true;
	}
	//Smilar to the methods of manage course
	bool addStu() {
		int i; string n; int g; string m; string mo; string e;
		cout << "Student Id: "; i = this->inputInt();
		while (!this->StuIDCheck(i)) {
			cout << "This id have been used, please input another: ";
			i = this->inputInt();
		}
		cout << "name: "; cin >> n;
		cout << "Grade: ";  g = this->inputInt();
		cout << "Major: ";  cin >> m;;
		cout << "Mobile: "; cin >> mo;
		while (!isNumber(mo)) {
			cout << "The mobile should be all number, please input again!" << endl;
			cin >> mo;
		}
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
	bool searchStu() {
		cout << "Input id (input \"*\" to list all students): ";
		string choice;
		cin >> choice;
		cout << setw(15) << "id" << setw(15) << "name" << setw(15) << "grade" << setw(15) << "major" << setw(15) << "mobile" << setw(15) << "email" << endl;
		int found = 0;
		if (choice == "*") {
			for (int i = 0; i < stu_info.size(); i++) {
				stu_info[i].show(); found++;
			}
		}
		else {
			for (int i = 0; i < stu_info.size(); i++) {
				if (to_string(stu_info[i].getId()) == choice) {
					stu_info[i].show(); found++;
				}
			}
		}
		if (found == 0) {
			cout << "No student found!" << endl;
		}

		return false;
	}

	bool deleteStu() {
		cout << "Enter the student ID you want to delete: ";
		int id;
		cin >> id;
		int found = 0;
		for (int i = 0; i < stu_info.size(); i++) {
			if (stu_info[i].getId() == id) {
				stu_info.erase(stu_info.begin() + i);
				found++;
				i--;
			}
		}
		if (found == 0) {
			cout << "No student found with the given ID" << endl;
			return false;
		}
		else {
			cout << "Student with ID " << id << " deleted successfully." << endl;
		}
		return false;
	}

	bool modifyStu() {
		cout << "Input the ID of the student you want to modify" << endl;
		int id;
		cin >> id;
		int found = 0;
		for (int i = 0; i < stu_info.size(); i++) {
			if (stu_info[i].getId() == id) {
				stu_info.erase(stu_info.begin() + i);
				found++;
				i--;
			}
		}
		if (found == 0) {
			cout << "No student found with the given ID" << endl;
			return false;
		}
		else {
			cout << "Please add the new infomation." << endl;
			while (this->addStu());
		}
		return false;
	}
	//Choose function to manage marks
	bool manageMar() {
		menu.manageMar();
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->addMar());
		}
		else if (choice == 2) {
			cout << "Input the Id: ";
			int id = inputInt(); int cindex = -1;
			for (int i = 0; i < stu_info.size(); i++) {
				if (stu_info[i].getId() == id) {
					cindex = i;
				}
			}
			if (cindex == -1) {
				cout << "No student found!" << endl;
				return false;
			}
			while (this->queryMark(stu_info[cindex]));
		}
		else if (choice == 3) {
			return false;
		}
		return true;
	}

	bool addMar() {
		//Find the mark of the terget student
		cout << "Input the student id" << endl;
		int id = inputInt();
		int sindex = -1;
		for (int i = 0; i < stu_info.size(); i++) {
			if (stu_info[i].getId() == id) {
				sindex = i;
			}
		}
		if (sindex == -1) {
			cout << "No student found!" << endl;
			return false;
		}
		//Choose the code of the terget course
		cout << "Please choose the course from below of which the mark will be input." << endl;
		cout << setw(15) << "Code" << setw(15) << "Name" << setw(15) << "Enoroll grade" << setw(15) << "Enoroll major" << endl;
		for (int i = 0; i < course_list.size(); i++) {
			course_list[i].print();
		}
		while (1) {
			cout << "Input the code:";
			string code;
			cin >> code;
			while (!this->CorIdCheck(code, stu_info[sindex].getCourseTaken())) {
				cout << "You have added it, please add another: ";
				cin >> code;
			}
			int cindex = -1;
			for (int i = 0; i < course_list.size(); i++) {
				if (course_list[i].getCode() == code) {
					cindex = i; stu_info[sindex].addCourse_taken(course_list[i]);//Store the course to the vector for taken course
					cout << "Please input the mark of the course " << course_list[i].getCode() << " for student with Id" << stu_info[sindex].getId() << endl;
					double mark;
					cin >> mark;
					stu_info[sindex].addMark(mark);//store the mark to the vector for marks
					cout << "Add mark successfully!" << endl;
				}
			}
			if (cindex == -1) {
				cout << "No course found!" << endl;
				break;
			}
			cout << "Do you want to add another mark for this student (1 for yes, 0 for no)?" << endl;
			int add = inputInt();
			if (add == 0) {
				break;
			}
		}

		return false;
	}
	//The menu for students to choose function
	bool Stu_menu() {
		menu.Stu_menu();
		int choice = this->inputInt();
		if (choice == 1) {
			while (this->chooseCourse());
		}
		else if (choice == 2) {
			while (this->queryMark(stu));
		}
		else if (choice == 3) {
			while (this->searchCor(stu.getCourseChosen()));
		}
		else if (choice == 4) {
			while (this->viewMyinfo());
		}
		else if (choice == 5) {
			return false;
		}
		return true;
	}
	bool chooseCourse() {
		cout << setw(15) << "Code" << setw(15) << "Name" << setw(15) << "Enoroll grade" << setw(15) << "Enoroll major" << endl;
		for (int i = 0; i < course_list.size(); i++) {
			course_list[i].print();
		}
		cout << "Please choose the code from above: " << endl;
		string choice;
		cin >> choice;
		if (choice == "quit") {
			return false;
		}
		while ((!this->CorIdCheck(choice, stu.getCourseChosen())) || (!this->CorIdCheck(choice, stu.getCourseTaken()))) {
			if (!this->CorIdCheck(choice, stu.getCourseChosen())) {
				cout << "You have chosen it, please choose another or input 'quit' to quit: ";
			}
			else {
				cout << "You have learnt it, please choose another or input 'quit' to quit: ";
			}
			cin >> choice;
		}if (choice == "quit") {
			return false;
		}
		int found = 0;
		for (int i = 0; i < course_list.size(); i++) {
			if (course_list[i].getCode() == choice) {
				found++;
				if (!(stu.getGrade() == course_list[i].getGrade())) {
					cout << "This course is not for your grade, please choose again or input 'quit' to quit" << endl;
					return true;
				}
				else if (!(stu.getMajor() == course_list[i].getMajor())) {
					cout << "This course is not for your major,please choose again or input 'quit' to quit!" << endl;
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
	bool queryMark(Student s) {
		vector<Course> c = s.getCourseTaken();
		vector<double>m = s.getMark();
		cout << setw(15) << "Course" << setw(15) << "Mark" << endl;
		for (int i = 0; i < c.size(); i++) {
			cout << setw(15) << c[i].getCode() << setw(15) << m[i] << endl;
		}
		return false;
	}
	bool viewMyinfo() {
		user_info->print();
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
	bool isNumber(string s) {
		for (int i = 0; i < s.size(); i++) {
			if (!isdigit(s[i])) {
				return false;
			}
		}
		return true;
	}
	bool CorIdCheck(string code, vector<Course>c) {
		for (int i = 0; i < c.size(); i++) {
			if (code == c[i].getCode()) {
				return false;
			}
		}
		return true;
	}

	bool StuIDCheck(int id) {
		for (int i = 0; i < stu_info.size(); i++) {
			if (id == stu_info[i].getId()) {
				return false;
			}
		}
		return true;
	}
	bool CorNameReapeat(string n) {
		for (int i = 0; i < course_list.size(); i++) {
			if (course_list[i].getName() == n) {
				return true;
			}
		}
		return false;
	}
};

