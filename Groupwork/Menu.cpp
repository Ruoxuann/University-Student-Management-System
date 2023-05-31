#include <iostream>

#include <string> 

using namespace std;

class Menu {
private:
    void StudentScore() {
        cout << endl;
        cout << "Please input the course for which you want to query scores： ";

    }

    void CourseChoose() {
        cout << endl;
        cout << "Your optional courses are as follows： ";
        cout << "**************************" << endl;
        cout << "* 1. CPT 106             *" << endl;
        cout << "* 2. CPT 103             *" << endl;
        cout << "* 3. MTH 102             *" << endl;
        cout << "* 4. EEE 112             *" << endl;
        cout << "* 5. EEE 104             *" << endl;
        cout << "**************************" << endl;
        cout << "Please input a number to run the program: ";
    }

public:
    Menu() {

        // 展示管理层菜单增删学生或课程数据及返回主菜单
        void showManagerMenu() {
            int option;
            do {
                cout << endl;
                cout << "Please choose your business： ";
                cout << "**************************" << endl;
                cout << "* 1. add student         *" << endl;
                cout << "* 2. add course          *" << endl;
                cout << "* 3. delete student      *" << endl;
                cout << "* 4. delete courses      *" << endl;
                cout << "* 5. move to parent menu *" << endl;
                cout << "**************************" << endl;
                cout << "Please input a number to run the program: ";

                cin >> option;

                switch (option) {
                case 1:
                    studentAdd();         //添加学生信息
                    break;
                case 2:
                    courseAdd();         //添加课程信息
                    break;
                case 3:
                    studentDelet();         //删除学生信息
                    break;
                case 4:
                    courseDelet();         //删除课程信息
                    break;
                case 5:
                    //回到菜单
                    break;
                }
            }
        }

        // 展示学生菜单：1-查询课程分数；2-选课
        void showStudentMenu() {
            int option;
            do {
                cout << endl;
                cout << "Please choose your business： ";
                cout << "*****************************" << endl;
                cout << "* Choose your business：    *" << endl;
                cout << "* 1. query score            *" << endl;
                cout << "* 2. choose courses         *" << endl;
                cout << "* 3. move to parent menu    *" << endl;
                cout << "*****************************" << endl;
                cout << "Please input a number to run the program: ";

                cin >> option;

                switch (option) {
                case 1:
                    StudentScore();         //跳转成绩查询
                    break;
                case 2:
                    CourseChoose();         //跳转选课系统
                    break;
                case 3:
                    //回到菜单
                    break;
                default:
                    cout << "Something wrong. Please try again." << endl;
                    break;
                }
            } while (option != 3);

        }

        // 主菜单界面（身份选择）：1-管理员；2-学生；3-退出主程序
        void start() {
            int option;
            do {
                cout << "Welcome to the University Student Management System! ";
                cout << "**************************" << endl;
                cout << "* 1. manager             *" << endl;
                cout << "* 2. student             *" << endl;
                cout << "* 3. quit the program    *" << endl;
                cout << "**************************" << endl;
                cout << "Please input a number to set your role: ";
                cin >> option;

                switch (option) {
                case 1:
                    managerLogin();         //跳转管理员登录
                    break;
                case 2:
                    studentLogin();         //跳转学生登录
                    break;
                case 3:
                    cout << "Thanks for using the University Student Management System. Goodbye!" << endl;
                    break;
                default:
                    cout << "Something wrong. Please try again." << endl;
                    break;
                }
            } while (option != 3);
        }

        //管理员登录界面
        void managerLogin() {
            string password;
            cout << "Input the manager password: ";     //输入密码
            cin >> password;
            if (password != "password") {
                cout << "Incorrect password. Access denied." << endl;   //密码不正确的情况
                return;
            }
            int option;
            do {
                showManagerMenu();                  //密码正确打开管理员菜单界面
            }
        }

        // 学生登录界面
        void studentLogin() {
            int studentID;
            cout << "Please Input your student ID: ";       //输入学生ID号
            cin >> studentID;

            int index = getStudentIndex(studentID);
            if (index == -1) {
                cout << "student not found. Access denied." << endl;    //学生号查询不到情况
                return;
            }

            currentStudent = &students[index];

            int option;
            do {
                showStudentMenu();              //学生登入后进入学生菜单界面
            }
        }
    }
}
    }
    };

