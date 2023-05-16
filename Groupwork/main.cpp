#include "Person.h" //0514 1947hqy加的
#include "Student.h" //0514 1947加
#include "Course.h"  //0514 1947加
#include"MainProcess.h"

#include<iostream>
using namespace std;

int main() {
	MainProcess m1;
	while (true) {
		if (m1.login() == false) {
			break;
		}
	}
	return 0;
}
