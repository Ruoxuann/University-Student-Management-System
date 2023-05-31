#include <iostream>

#include <string> 

using namespace std;

class Menu {

	void UserType() {
        cout << endl;
        cout << "***********************************" << endl;
        cout << "*  Please input your student ID:  *" << endl;
        cout << "***********************************" << endl;
        cout << "Please input a number to run the program: ";
	}

    void SignUp() {
        cout << endl;
        cout << "**************************" << endl;
        cout << "* 1. student             *" << endl;
        cout << "* 2. administrater       *" << endl;
        cout << "* 3. quit                *" << endl;
        cout << "**************************" << endl;
    }

    void Ad_menu() {
        cout << endl;
        cout << "**************************" << endl;
        cout << "* 1. add                 *" << endl;
        cout << "* 2. search for mark     *" << endl;
        cout << "* 3. delete              *" << endl;
        cout << "* 4. modify the mark     *" << endl;
        cout << "* 5. check course choose *" << endl;
        cout << "**************************" << endl;
        cout << "Please input a number to run the program: ";
    }

    void manageCourse() {
        cout << endl;
        cout << "**************************" << endl;
        cout << "* 1. add                 *" << endl;
        cout << "* 2. search for course   *" << endl;
        cout << "* 3. delete              *" << endl;
        cout << "* 4. quit                *" << endl;
        cout << "**************************" << endl;
        cout << "Please input a number to run the program: ";
    }

    void manageStu() {
        cout << endl;
        cout << "**************************" << endl;
        cout << "* 1. add                 *" << endl;
        cout << "* 2. search for student  *" << endl;
        cout << "* 3. delete              *" << endl;
        cout << "* 4. quit                *" << endl;
        cout << "**************************" << endl;
        cout << "Please input a number to run the program: ";
    }

    void Stu_menu() {
        cout << endl;
        cout << "*****************************" << endl;
        cout << "* 1. choose course          *" << endl;
        cout << "* 2. query mark             *" << endl;
        cout << "* 3. view the chosen course *" << endl;
        cout << "* 4. quit                   *" << endl;
        cout << "*****************************" << endl;
        cout << "Please input a number to run the program: ";
    }

    void chooseCourse() {
        cout << endl;
        cout << "********************" << endl;
        cout << "* Code             *" << endl;
        cout << "* Name             *" << endl;
        cout << "* Enoroll grade    *" << endl;
        cout << "* Enoroll major    *" << endl;
        cout << "********************" << endl;
    }
};