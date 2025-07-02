#include<iostream>

#include <string> 

using namespace std;

class Menu {
public:

    void SignUp() {
        cout << "***********************************" << endl;
        cout << "*  Please input your student ID:  *" << endl;
        cout << "***********************************" << endl;
        // cout << "Please input a number to run the program: ";
    }

    void UserType() {
        cout << "**************************" << endl;
        cout << "* 1. student             *" << endl;
        cout << "* 2. administrater       *" << endl;
        cout << "* 3. quit                *" << endl;
        cout << "**************************" << endl;
    }

    void Ad_menu() {
        cout << "****************************" << endl;
        cout << "* 1. manage courses        *" << endl;
        cout << "* 2. manage students       *" << endl;
        cout << "* 3. manage marks          *" << endl;
        cout << "* 4. set my information    *" << endl;
        cout << "* 5. view my information   *" << endl;
        cout << "* 6. quit                  *" << endl;
        cout << "****************************" << endl;
        cout << "Please input a number to run the program: ";
    }

    void manageCourse() {
        cout << "**************************" << endl;
        cout << "* 1. add courses         *" << endl;
        cout << "* 2. search for course   *" << endl;
        cout << "* 3. delete courses      *" << endl;
        cout << "* 4. modify courses      *" << endl;
        cout << "* 5. quit                *" << endl;
        cout << "**************************" << endl;
        cout << "Please input a number to run the program: ";
    }

    void manageStu() {
        cout << endl;
        cout << "**************************" << endl;
        cout << "* 1. add student         *" << endl;
        cout << "* 2. search for student  *" << endl;
        cout << "* 3. delete student      *" << endl;
        cout << "* 4. modify student      *" << endl;
        cout << "* 5. quit                *" << endl;
        cout << "**************************" << endl;
        cout << "Please input a number to run the program: ";
    }

    void Stu_menu() {
        cout << "*******************************" << endl;
        cout << "* 1. choose course            *" << endl;
        cout << "* 2. query mark               *" << endl;
        cout << "* 3. view the chosen course   *" << endl;
        cout << "* 4. view my information      *" << endl;
        cout << "* 5. quit                     *" << endl;
        cout << "*******************************" << endl;
        cout << "Please input a number to run the program: ";
    }

    void chooseCourse() {
        cout << "********************" << endl;
        cout << "* Code             *" << endl;
        cout << "* Name             *" << endl;
        cout << "* Enoroll grade    *" << endl;
        cout << "* Enoroll major    *" << endl;
        cout << "********************" << endl;
    }

    void manageMar() {
        cout << "**************************" << endl;
        cout << "* 1. add mark            *" << endl;
        cout << "* 2. search for mark     *" << endl;
        cout << "* 3. quit                *" << endl;
        cout << "**************************" << endl;
    }
};

