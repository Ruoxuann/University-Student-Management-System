#include "Person.h" 
#include "Student.h" 
#include "Course.h"  
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
