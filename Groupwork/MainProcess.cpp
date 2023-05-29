#include <iostream>

#include <string> 

using namespace std;

class MainProcess {
private:
    void StudentScore() {
        cout << endl;
        cout << "Please input the course for which you want to query scores�� ";
        
    }

    void CourseChoose() {
        cout << endl;
        cout << "Your optional courses are as follows�� ";
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
    MainProcess() {

        // չʾ�����˵���ɾѧ����γ����ݼ��������˵�
        void showManagerMenu() {
            int option;
            do {
                cout << endl;
                cout << "Please choose your business�� ";
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
                    studentAdd();         //���ѧ����Ϣ
                    break;
                case 2:
                    courseAdd();         //��ӿγ���Ϣ
                    break;
                case 3:
                    studentDelet();         //ɾ��ѧ����Ϣ
                    break;
                case 4:
                    courseDelet();         //ɾ���γ���Ϣ
                    break;
                case 5:
                    //�ص��˵�
                    break;
                }
            }
            }

            // չʾѧ���˵���1-��ѯ�γ̷�����2-ѡ��
            void showStudentMenu() {
                int option;
                do {
                    cout << endl;
                    cout << "Please choose your business�� ";
                    cout << "*****************************" << endl;
                    cout << "* Choose your business��    *" << endl;
                    cout << "* 1. query score            *" << endl;
                    cout << "* 2. choose courses         *" << endl;
                    cout << "* 3. move to parent menu    *" << endl;
                    cout << "*****************************" << endl;
                    cout << "Please input a number to run the program: ";
                    
                    cin >> option;

                    switch (option) {
                    case 1:
                        StudentScore();         //��ת�ɼ���ѯ
                        break;
                    case 2:
                        CourseChoose();         //��תѡ��ϵͳ
                        break;
                    case 3:
                                                //�ص��˵�
                        break;
                    default:
                        cout << "Something wrong. Please try again." << endl;
                        break;
                    }
                } while (option != 3); 

            }

            // ���˵����棨���ѡ�񣩣�1-����Ա��2-ѧ����3-�˳�������
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
                        managerLogin();         //��ת����Ա��¼
                        break;
                    case 2:
                        studentLogin();         //��תѧ����¼
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

            //����Ա��¼����
            void managerLogin() {
                string password;
                cout << "Input the manager password: ";     //��������
                cin >> password;
                if (password != "password") {
                    cout << "Incorrect password. Access denied." << endl;   //���벻��ȷ�����
                    return;
                }
                int option;
                do {
                    showManagerMenu();                  //������ȷ�򿪹���Ա�˵�����
                }
            }

            // ѧ����¼����
            void studentLogin() {
                int studentID;
                cout << "Please Input your student ID: ";       //����ѧ��ID��
                cin >> studentID;

                int index = getStudentIndex(studentID);
                if (index == -1) {
                    cout << "student not found. Access denied." << endl;    //ѧ���Ų�ѯ�������
                    return;
                }

                currentStudent = &students[index];

                int option;
                do {
                    showStudentMenu();              //ѧ����������ѧ���˵�����
                }
            }
        }
    }
    }
    };