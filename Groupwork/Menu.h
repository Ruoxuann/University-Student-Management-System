#include <iostream>
using namespace std;
#pragma once

class Menu {
public:
    //登录界面
    void login() {
        cout << "***************************************" << endl;
        cout << "*  Please select the function：       *" << endl;
        cout << "*  1.Information registration         *" << endl;  //跳转学生信息登入
        cout << "*  2.Choose user type                 *" << endl;  
        cout << "***************************************" << endl;
    }
    //学生信息登入界面
    void SignUp() {
        cout << "***************************************" << endl;
        cout << "*           student name              *" << endl;
        cout << "*             ID number               *" << endl;
        cout << "***************************************" << endl;
    }

    //课程选择界面（课程信息）
    void ClassChoosen() {
        cout << "***************************************" << endl;
        cout << "*              Class 1                *" << endl;
        cout << "*              Class 2                *" << endl;
        cout << "*              Class 3                *" << endl;
        cout << "***************************************" << endl;
    }

    //不同用户类型（登入管理员系统）
    void UserType() {
        cout << "***************************************" << endl;
        cout << "*              student                *" << endl;
        cout << "*           administrator             *" << endl;
        cout << "***************************************" << endl;
    }

};

