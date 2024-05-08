#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
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
                        masterFlag = true;
                        break;
                    } else {
                        masterFlag = false;
                    }
                }
                if (masterFlag == true) {
                    cout << "You have successfully logged in as a master\n";
                    //----------------------------------MASTER MENU (start)---------------------------------------
                    while (masterFlag) {
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
                        cin >> ans;

                        int qnumber, qtime, score;
                        string name;
                        if (ans == 0)//Back to menu
                        {
                            masterFlag = false;
                            break;
                        }
                        else if (ans == 1)//Add a list of students
                        {
                            string userSTR = "";
                            cout << "Please enter your students list name : \n";
                            getline(cin >> ws, userSTR);
                            Master::ListMaker(userSTR);

                            fstream studenlist;
                            studenlist.open("StudentsListName.txt", ios :: app);//Add list name to StudentsListName.txt
                            if(studenlist.is_open()){
                                studenlist << userSTR << endl;
                            }

                            cout << "Your list has been successfully created.\n";
                        }
                        else if (ans == 2)//Making a test exam
                        {
                            cout << "Please enter your exam name : \n";
                            getline(cin >> ws, name);
                            cout << "Please enter the number of questions in your exams: \n";
                            cin >> qnumber;
                            cout << "Please enter the total exam score: \n";
                            cin >> score;
                            cout << "Please enter the exam time: \n";
                            cin >> qtime;
                            ExamTest quiz(name, score, qnumber, qtime);
                            if (quiz.ExamTestCreator()) {
                                cout << "Your test was created successfully. \n";
                            } else {
                                cout << "It seems that the process of making the exam had a problem!";
                            }
                        }
                        else if (ans == 3)//Making a writing exam
                        {
                            cout << "Please enter your exam name : \n";
                            getline(cin >> ws, name);
                            cout << "Please enter the number of questions in your exams: \n";
                            cin >> qnumber;
                            cout << "Please enter the total exam score: \n";
                            cin >> score;
                            cout << "Please enter the exam time: \n";
                            cin >> qtime;
                            ExamWritten quiz(name, score, qnumber, qtime);
                            if (quiz.ExamWrittenCreator()) {
                                cout << "Your test was created successfully. \n";
                            } else {
                                cout << "It seems that the process of making the test exam had a problem!";
                            }

                        }
                        else if (ans == 4)//View student lists and add students
                        {
                            while (true) {
                                int innerAns = 0;
                                cout << " 0.Back \n 1.See all students \n 2.Add a new student\n ";
                                cin >> innerAns;
                                if (innerAns == 0) {//Back
                                    break;
                                }
                                else if (innerAns == 1)//See all students
                                {
                                    cout << "List of all students:\n";
                                    string innerLine = "";
                                    fstream studentcrfile;
                                    studentcrfile.open("StudentsDB.txt", ios::in); //print students
                                    if (studentcrfile.is_open()) {
                                        int *counter = new int(1);
                                        while (getline(studentcrfile, innerLine)) {

                                            cout << *counter << "-" << innerLine << endl;
                                            ++*counter;
                                        }
                                        studentcrfile.close();
                                        cout << "Students list have successfully printed.\n";
                                    }
                                }
                                else if (innerAns == 2)//Add a new student
                                {
                                    cout << "Please enter the student's username and password: ";
                                    string innerInput = "";
                                    getline(cin >> ws, input);

                                    if (!Master::UserNameChecker("MastersDB.txt", input, true)) {
                                        fstream studentcrfile;
                                        studentcrfile.open("StudentsDB.txt", ios::app); //append to student file
                                        if (studentcrfile.is_open()) {
                                            studentcrfile << endl << input;
                                            cout << "\nThe student account has been created successfully.\n";
                                            studentcrfile.close();
                                        } else {
                                            cout << "Unknown request!\n";
                                        }
                                    } else {
                                        cout << "Username is already selected!" << endl;
                                        continue;
                                    }

                                }
                            }
                        }
                        else if (ans == 5)//History of exams
                        {
                            while (true) {
                                int innerans = 0;
                                cout << "0.Back  1.Exams list  2.Done exams list  3.View full exam\n";
                                cin >> innerans;
                                if (innerans == 0) {//Back
                                    break;
                                }
                                else if (innerans == 1) {
                                    cout << "List of all exams:\n";
                                    string innerLine = "";
                                    fstream examlist;
                                    examlist.open("ExamsName.txt", ios::in);//print exams
                                    if (examlist.is_open()) {
                                        int counter = 1;
                                        bool flag = true;
                                        while (getline(examlist, innerLine)) {
                                            if (innerLine != "") {
                                                cout << counter << "-" << innerLine << endl;
                                                counter++;
                                                flag = false;
                                            }
                                        }
                                        if (flag) {
                                            cout << "List is empty!\n\n";
                                        } else {
                                            cout << "Exams list have successfully printed.\n\n";
                                        }
                                        examlist.close();
                                    }
                                }
                                else if (innerans == 2) {
                                    cout << "List of all done exams:\n";
                                    string innerLine = "";
                                    fstream doneexamlist;
                                    doneexamlist.open("DoneExamsList.txt", ios::in);//print done exams
                                    if (doneexamlist.is_open()) {
                                        int counter = 0;
                                        bool flag = true;
                                        while (getline(doneexamlist, innerLine)) {
                                            if (innerLine != "") {
                                                cout << counter << "-" << innerLine << endl;
                                                counter++;
                                                flag = false;
                                            }
                                        }
                                        if (flag) {
                                            cout << "List is empty!\n\n";
                                        } else {
                                            cout << "Exams list have successfully printed.\n\n";
                                        }
                                        doneexamlist.close();
                                    }

                                }
                                else if(innerans == 3) {
                                    cout << "Enter your exam name(if it's the test exam then please add 'Test' to the end of your exam's name):\n";
                                    string input = "";
                                    bool flag = true;
                                    string temp = "";

                                    getline(cin >> ws, input);
                                    string line = "";
                                    fstream examnamefile;
                                    examnamefile.open("ExamsName.txt", ios :: in);
                                    if(examnamefile.is_open()){
                                        while(getline(examnamefile, line)){
                                            if(line == input){
                                                temp = line;
                                                flag = false;
                                                break;
                                            }
                                        }
                                    }
                                    examnamefile.close();
                                    if(!flag){
                                        fstream exam;
                                        string examname = "ExamList/" + temp + ".txt";
                                        exam.open(examname, ios :: in);
                                        string templine = "";
                                        if(exam.is_open()){
                                            while(getline(exam, templine)){
                                                cout << templine << endl;
                                            }
                                        }
                                        exam.close();
                                        cout << "Your exam has successfully printed!\n";

                                    }else{
                                        cout << "Your exam does not found\n";
                                    }
                                }else {
                                    cout << "Unknown request!\n";
                                }
                            }

                        }
                        else if (ans == 6)//Add list to exams
                        {
                            while(true)
                            {
                                cout << "Enter your students list name(enter 'exit' to back to the master menu):\n";
                                string strInput = "";
                                getline(cin >> ws, strInput);
                                if(strInput != "exit") {
                                    fstream StudentListName;
                                    string line = "";

                                    StudentListName.open("StudentsListName.txt", ios::in);
                                    if (StudentListName.is_open()) {
                                        bool F= false,IF= false;
                                        while (getline(StudentListName, line))
                                        {
                                            if (line == strInput)
                                            {
                                                line = strInput;
                                                F= true;
                                                break;
                                            }
                                        }
                                            if (F) {
                                                string innerStrInput = "";
                                                cout<< "Ok!\nEnter your exam name(if it's the test exam then please add 'Test' to the end of your exam's name): \n";
                                                getline(cin >> ws, innerStrInput);
                                                fstream ExamName;
                                                ExamName.open("ExamsName.txt", ios::in);

                                                if (ExamName.is_open()) {
                                                    string innerline = "";
                                                    while (getline(ExamName, innerline))
                                                    {
                                                        if (innerStrInput == innerline)
                                                        {
                                                            innerStrInput = innerline;
                                                            IF= true;
                                                            break;
                                                        }
                                                    }

                                                        if (IF) {
                                                            fstream StudentListExam;
                                                            string exam = "ExamList/" + innerStrInput + ".txt";
                                                            StudentListExam.open(exam, ios::app);
                                                            if (StudentListExam.is_open()) {
                                                                StudentListExam << endl << "For students of "
                                                                                << strInput << endl;
                                                            }
                                                            StudentListExam.close();
                                                            cout<< "Your students list has successfully added to your exam.\n\n";
                                                            break;
                                                        } else {
                                                            cout << "Your exam does not found!\n\n";

                                                        }

                                                }
                                                ExamName.close();
                                            } else {
                                                cout << "Your student list name does not found!\n\n";

                                            }

                                    }
                                    StudentListName.close();
                                }else{
                                    break;
                                }
                            }
                        }
                        else if (ans == 7)//Result of exams
                        {
                            string inpute = "",line="";
                            int counter =1;
                            cout<<"Please, after viewing the names of the exam files, enter the file name in full to view the desired file(enter 'exit' to back to the master menu).\n";
                            fstream  FileShow;

                            FileShow.open("CorrectedExamsName.txt",ios::in);
                            while (getline(FileShow,line))
                            {
                                cout<<counter<<"_ "<<line<<endl;
                                ++counter;
                            }
                            FileShow.close();
                            cout<<"\n------------------------------------------------------------------------------\n";
                            while (true)
                            {
                                bool F= false;
                                cout<<"Enter name or exit : \n";
                                getline(cin>>ws , inpute);
                                if (input != "exit")
                                {
                                    fstream  FileShow;
                                    FileShow.open("CorrectedExamsName.txt",ios::in);
                                    while (getline(FileShow,line))
                                    {
                                        if (line == inpute)
                                        {
                                            F= true;
                                            break;
                                        }
                                    }
                                    FileShow.close();

                                    if (F)
                                    {
                                        string innerLine="";
                                        fstream FullShow;
                                        FullShow.open("CorrectedExamList/"+line+".txt",ios::in);
                                        while (getline(FullShow,innerLine))
                                        {
                                            cout<<innerLine<<endl;
                                        }
                                        FullShow.close();
                                    }
                                    else
                                    {
                                        cout<<"The exam you entered is not available!\n";
                                        continue;
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }


                        }
                        else if (ans == 8)//Correcting exams
                        {
                            while (true)
                            {
                                cout << "Please select the name of the exam you want to correct from the list below and enter it.(enter 'exit' to back to the master menu):\n \n";
                                string line = "", ans = "";
                                int *counter = new int(1);
                                fstream DoneExamsFile1;
                                DoneExamsFile1.open("DoneExamsName.txt",ios::in);
                                while (getline(DoneExamsFile1,line)) {
                                  cout<<*counter<<"_ "<<line<<endl;
                                  ++ *counter;
                                }
                                DoneExamsFile1.close();
                                fstream DoneExamsFile2;
                                DoneExamsFile2.open("DoneExamsName.txt",ios::in);
                                cout<<endl<<"Name of the exam you want: ";
                                getline(cin>>ws,ans);
                                if (ans!="exit") {
                                    bool F = false;
                                    while (getline(DoneExamsFile2, line)) {
                                        if (line == ans)
                                        {
                                            F = true;
                                            break;
                                        }
                                    }
                                    DoneExamsFile2.close();
                                    if (F)
                                    {
                                        string STR="",description="";
                                        int counter=1,score=0,number=0;
                                        cout<<"The questions are displayed in order. In the first line, enter the desired text and in the next line,\n";
                                        cout<<" enter the score according to the right answer of the same question.\n \n";
                                        fstream NewFileInCorrected;
                                        fstream OldFileInDone;
                                        NewFileInCorrected.open("CorrectedExamList/"+ans+".txt",ios::out);
                                        OldFileInDone.open("DoneExamList/"+ans+".txt",ios::in);
                                        while (getline(OldFileInDone,STR))
                                        {
                                            if (counter >= 4 && counter % 2 == 0)
                                            {
                                              NewFileInCorrected<<STR<<endl;
                                                cout<<STR<<endl;
                                                ++ counter;
                                            }
                                            else if (counter >= 4 && counter % 2 != 0)
                                            {
                                                NewFileInCorrected<<STR<<endl;
                                                cout<<STR<<endl<<"Description : ";
                                                getline(cin>>ws,description);
                                                NewFileInCorrected<<"Master description : "<<description<<endl;
                                                cout<< "Score : ";
                                                cin>>number;
                                                NewFileInCorrected<<"Master's score : "<<number<<endl;
                                                score += number;
                                                ++ counter;
                                            }
                                            else
                                            {
                                                ++ counter;
                                                continue;
                                            }
                                        }
                                        NewFileInCorrected<<"Total score is : "<<score;
                                        //در این جا باید نام فایل امتحانات رو در لیست تکست هایی که مشخص کردیم حذف و اضافه کنیم
                                        NewFileInCorrected.close();
                                        OldFileInDone.close();

                                        string filename="DoneExamList/"+ans+".txt";
                                        remove(filename.c_str());
                                        //Adding to text file
                                        fstream Correctedtext;
                                        Correctedtext.open("CorrectedExamsName.txt",ios::app);
                                        Correctedtext<<ans<<endl;
                                        Correctedtext.close();

                                        //Delete from  text file
                                        fstream Donetext;
                                        Donetext.open("DoneExamsName.txt",ios::app);

                                        fstream temp;
                                        temp.open("temp.txt",ios::app);
                                          string s="";
                                        while (getline(Donetext,s))
                                        {
                                            if (s != ans)
                                            {
                                                temp<<s<<endl;
                                            }
                                        }

                                        filename="DoneExamsName.txt";
                                        temp.close();
                                        Donetext.close();
                                        remove(filename.c_str());
                                        rename("temp.txt","DoneExamsName.txt");
                                        continue;
                                    }
                                    else
                                    {
                                        cout<<"The exam you entered does not exist! \n";
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        else

                        {
                            cout << "Unknown request!\n";//goes to master menu
                            continue;
                        }

                    }
                }
                        //----------------------------------MASTER MENU (end)---------------------------------------
                    else {
                            cout << "Invalid username or password!\n\n";
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

                if (! Master::UserNameChecker("MastersDB.txt",input, true)) {
                    fstream mastercrfile;
                    mastercrfile.open("MastersDB.txt", ios::app); //append to master file
                    if (mastercrfile.is_open()) {
                        mastercrfile << endl << input;
                        cout << "\nYou have successfully created an account.\n";
                        mastercrfile.close();
                    }
                }
                else
                {
                    cout<<"Username is already exist!"<<endl;
                    continue;
                }
            } else if (op2 == "student") {
                cout << "Please enter a username and a password: ";
                string input = "";
                getline(cin >> ws, input);

                if (!Master::UserNameChecker("StudentsDB.txt", input, true)) {
                    fstream studentcrfile;
                    studentcrfile.open("StudentsDB.txt", ios::app); //append to student file
                    if (studentcrfile.is_open()) {
                        studentcrfile << endl << input;
                        cout << "\nYou have successfully created an account.\n";
                        studentcrfile.close();
                    }
                }
                else
                {
                    cout << "Username is already exist!"<< endl;
                    continue;
                }
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
