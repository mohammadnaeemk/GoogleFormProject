#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Master.h"
#include "Student.h"
#include "Exam.h"
#include "ExamWritten.h"
#include "ExamTest.h"

using namespace std;

int main() {
    bool flag= true;
    while(flag) {

        cout << "Login as master or student or creat an account (press 1 or 2 or 3 for login and 0 for exit)\n"
                " 0. exit\n "
                "1. Student\n "
                "2. Master\n "
                "3. Register\n";
        int op = 0;
        cin >> op;
        if (op == 1) {
            cout << "Please enter your username and password(Enter 0 to return to the main menu):";
            string input = "";
            getline(cin >> ws, input);
            if (input=="0")
            {
                continue;//back to menu
            }
            fstream studentfile;
            studentfile.open("StudentsDB.txt", ios::in);//read from students file
            if (studentfile.is_open()) {
                string line;
                while (getline(studentfile, line)) { //search for student
                    if (line == input) {
                        cout << "You have successfully logged in as a student\n";
                    } else {
                        cout << "Invalid username or password!\n\n";
                        continue; //goes to menu page
                    }
                }
                studentfile.close();
            }

        }
        if (op == 2) {
            cout << "Please enter your username and password(enter 0 to return to the main menu):";
            string input = "";
            getline(cin >> ws, input);
            if (input == "0")
            {
                continue; //Back to menu
            }
            fstream masterfile;
            masterfile.open("MastersDB.txt", ios::in);//read from master file
            if (masterfile.is_open()) {
                string line;
                bool masterFlag= true;
                while (getline(masterfile, line)) { //search for master
                    if (line == input) {
                        cout << "You have successfully logged in as a master\n";
                        //----------------------------------MASTER MENU (start)---------------------------------------
                        while (masterFlag)
                        {
                            int ans;
                            cout << "Choose your desired option from the menu below...\n"
                                    " 0. Back to the main menu.\n "
                                    "1. Add a list of students.\n "
                                    "2. Making a test exam.\n "
                                    "3. Making a written exam.\n"
                                    " 4. View students list and add students.\n"
                                    " 5. History of exams.\n"
                                    " 6. Add list to exams.\n"
                                    " 7. Result of exams.\n"
                                    " 8. Correcting exams.\n";
                            cin>>ans;

                            int qnumber,qtime,score;
                            string name;
                            if (ans==0)//Back to menu
                            {
                                masterFlag = false;
                                break;
                            }
                            else if (ans==1)//Add a list of students
                            {

                            }
                            else if (ans == 2)//Making a test exam
                            {
                                cout<<"Please enter your exam name : \n";
                                getline(cin>>ws,name);
                                cout<<"Please enter the number of questions in your exams: \n";
                                cin>>qnumber;
                                cout<<"Please enter the total exam score: \n";
                                cin >> score;
                                cout<<"Please enter the exam time: \n";
                                cin>>qtime;
                                ExamTest quiz(name, score, qnumber, qtime);
                                if (quiz.ExamTestCreator())
                                {
                                    cout<<"Your test was created successfully. \n";
                                }
                                else
                                {
                                    cout<<"It seems that the process of making the exam had a problem!";
                                }
                            }
                            else if (ans == 3)//Making a writing exam
                            {
                                cout<<"Please enter your exam name : \n";
                                getline(cin>>ws,name);
                                cout<<"Please enter the number of questions in your exams: \n";
                                cin>>qnumber;
                                cout<<"Please enter the total exam score: \n";
                                cin >> score;
                                cout<<"Please enter the exam time: \n";
                                cin>>qtime;
                                ExamWritten quiz(name, score, qnumber, qtime);
                                if (quiz.ExamWrittenCreator())
                                {
                                    cout<<"Your test was created successfully. \n";
                                }
                                else
                                {
                                    cout<<"It seems that the process of making the test exam had a problem!";
                                }

                            }
                            else if (ans == 4)//View student lists and add students
                            {
                                while (true) {
                                    int innerAns = 0;
                                    cout << " 0.Back  1.See all students  2.Add a new student\n ";
                                    cin >> innerAns;
                                    if (innerAns == 0) {//Back
                                        break;
                                    }
                                    else if (innerAns == 1)//See all students
                                    {
                                        cout << "List of all students:\n";
                                        string innerLine= "";
                                        fstream studentcrfile;
                                        studentcrfile.open("StudentsDB.txt", ios::in); //print students
                                        if (studentcrfile.is_open()) {
                                            int * counter = new int(1) ;
                                            while (getline(studentcrfile,innerLine)){

                                               cout << *counter << "-" << innerLine << endl;
                                               ++ *counter;
                                            }
                                            studentcrfile.close();
                                            cout<<"Students list have successfully printed.\n";
                                        }
                                    }
                                    else if (innerAns == 2)//Add a new student
                                    {
                                        cout << "Please enter the student's username and password: ";
                                        string innerInput = "";
                                        getline(cin >> ws, input);
                                        fstream studentcrfile;
                                        studentcrfile.open("StudentsDB.txt", ios::app); //append to student file
                                        if (studentcrfile.is_open()) {
                                            studentcrfile << endl << input;
                                            cout << "\nThe student account has been created successfully.\n";
                                            studentcrfile.close();
                                        }
                                    }else{
                                        cout << "Unknown request!\n";
                                    }
                                }
                            }
                            else if (ans==5)//History of exams
                            {
                                while(true){
                                    int innerans = 0;
                                    cout << "0.Back  1.Exams list  2.Done exams list\n";
                                    cin >> innerans;
                                    if(innerans == 0){//Back
                                        break;
                                    }
                                    else if(innerans == 1){
                                        cout << "List of all exams:\n";
                                        string innerLine = "";
                                        fstream examlist;
                                        examlist.open("ExamsName.txt", ios::in);//print exams
                                        if(examlist.is_open()){
                                            int counter = 1;
                                            bool flag = true;
                                            while(getline(examlist, innerLine)) {
                                                if (innerLine != "") {
                                                    cout << counter << "-" << innerLine << endl;
                                                    counter++;
                                                    flag = false;
                                                }
                                            }
                                            if(flag){
                                                cout << "List is empty!\n\n";
                                            }else{
                                                cout << "Exams list have successfully printed.\n\n" ;
                                            }
                                            examlist.close();
                                        }
                                    }
                                    else if(innerans == 2){
                                        cout << "List of all done exams:\n";
                                        string innerLine = "";
                                        fstream doneexamlist;
                                        doneexamlist.open("DoneExamsList.txt", ios::in);//print done exams
                                        if(doneexamlist.is_open()){
                                            int counter = 0;
                                            bool flag = true;
                                            while(getline(doneexamlist, innerLine)) {
                                                if (innerLine != "") {
                                                    cout << counter << "_" << innerLine << endl;
                                                    counter++;
                                                    flag = false;
                                                }
                                            }
                                            if(flag){
                                                cout << "List is empty!\n\n";
                                            }else{
                                                cout << "Exams list have successfully printed.\n\n" ;
                                            }
                                            doneexamlist.close();
                                        }

                                    }else{
                                        cout << "Unknown request!\n";
                                    }
                                }

                            }
                            else if (ans==6)//Add list to exams
                            {

                            }
                            else if (ans==7)//Result of exams
                            {

                            }
                            else if (ans==8)//Correcting exams
                            {

                            }else{
                                cout << "Unknown request!\n";//goes to master menu
                                continue;
                            }

                        }
                        //----------------------------------MASTER MENU (end)---------------------------------------
                    } else {
                        if(!masterFlag){
                            continue;
                        }else {
                            cout << "Invalid username or password!\n\n";
                            break; //goes to main menu page
                        }
                    }
                }
                masterfile.close();
            }

        }
        if (op == 3) {
            string op2;
            cout << "Are you master or student?(Enter 0 to return to the main menu) ";
            cin >> op2;
            if (op2 == "master") {
                cout << "Please enter a username and a password:";
                string input = "";
                getline(cin >> ws, input);
                fstream mastercrfile;
                mastercrfile.open("MastersDB.txt", ios::app); //append to master file
                if (mastercrfile.is_open()) {
                    mastercrfile << endl << input;
                    cout << "\nYou have successfully created an account.\n";
                    mastercrfile.close();
                }
            } else if (op2 == "student") {
                cout << "Please enter a username and a password: ";
                string input = "";
                getline(cin >> ws, input);
                fstream studentcrfile;
                studentcrfile.open("StudentsDB.txt", ios::app); //append to student file
                if (studentcrfile.is_open()) {
                    studentcrfile << endl << input;
                    cout << "\nYou have successfully created an account.\nlogging in...\n";
                    studentcrfile.close();
                }
                cout << "You have successfully logged in as student\n";
            }
            else if (op2 =="0")
            {
                continue;
            }
        }
        if (op == 0) {
           cout << "\nThanks for your cooperation (:\n";
           flag= false;
        }
    }
    return 0;
}
