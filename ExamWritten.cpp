// ExamWritten.cpp file
#include "ExamWritten.h"
#include "Exam.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
using namespace std;
using namespace std::chrono;
//constructor
ExamWritten::ExamWritten(string examname, int totalScore, int numberquestins, int timenum) : Exam(examname,totalScore, numberquestins, timenum) {}


//for build Exam Written
bool ExamWritten::ExamWrittenCreator()
{
    fstream ExamFile;
    string fileName="";

    fileName=examName;
    fileName = "ExamList/"+ fileName + ".txt";
    ExamFile.open(fileName, ios::out);//creat written exam file
    ExamFile.close();
    fstream ExamFileEdit;
    ExamFileEdit.open(fileName,ios::app);
    ExamFileEdit << "Number of questions : " << numberOfQuestions << endl;
    ExamFileEdit << "Time : " << timeM << endl;
    ExamFileEdit << "Total score : " << score << endl;

    for (int i = 1; i <= numberOfQuestions ; ++i) {
        string text=to_string(i),temp="";
        cout<<"Please enter the text of question "<< i <<" : \n";
        getline(cin>>ws,temp);

        text += ") ";
        text = text+ temp + "\n";
        ExamFileEdit<<text;
    }
    ExamFileEdit.close();

    fstream Examname; //adding exam name to ExamsList.txt
    Examname.open("ExamsName.txt", ios::app);
    Examname << examName << endl;
    Examname.close();

    return true;
}


void ExamWritten::takeDescriptiveExam( string examName, string userName) {
    string strCheck1="",strCheck2="",Line;
    strCheck1 = userName;
    fstream file;
    file.open("StudentsDB.txt",ios::in);
    if (file.is_open()){
        while (getline(file,Line)) {
            for (int i = Line.size() - 1; i >= 0; --i) {
                if (Line[i] == ' ') {
                    strCheck2 = Line.substr(0, i);
                    file.close();
                    break;
                }
            }
        }
    }
    userName = strCheck2;

    fstream exam;
    fstream donExam;
    exam.open("ExamList/" + examName + ".txt", ios::in);
    donExam.open("DoneExamList/" + userName + "_" + examName + ".txt", ios::app);

    if (!exam.is_open() || !donExam.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    int numberOfQuestions = 0;
    int examTime = 0; // in minutes

    // خواندن تعداد سوالات و زمان امتحان از فایل
    getline(exam, line);
    donExam << line << endl;
    cout<< line << endl;
    numberOfQuestions = stoi(line.substr(line.find(":") + 1));
    getline(exam, line);
    donExam << line << endl;
    cout<<line << endl;
    examTime = stoi(line.substr(line.find(":") + 1));

    // زمان شروع امتحان
    auto start = system_clock::now();
    time_t startTime = system_clock::to_time_t(start);

    // خواندن و پاسخ به سوالات
    for (int i = 0; i < numberOfQuestions; i++) {
        if (system_clock::now() - start > minutes(examTime)) {
            cout << "Time is up!" << endl;
            break;
        }

        getline(exam, line);
        donExam << line << endl; // نوشتن صورت سوال در فایل
        cout << line << endl;

        string answer;
        cout << "Your answer: ";

        getline(cin>>ws, answer);
        donExam << answer << "\n";  // نوشتن جواب در فایل
    }

    // زمان پایان امتحان
    auto end = system_clock::now();
    time_t endTime = system_clock::to_time_t(end);

    // ثبت زمان شروع و پایان در یک خط
    donExam << "Exam duration: Start -" << ctime(&startTime) << "/End -" << ctime(&endTime);

    exam.close();
    donExam.close();

    // افزودن نام امتحان به فایل DoneExamsName.txt
    fstream doneExamsName;
    doneExamsName.open("DoneExamsName.txt", ios::app);
    if (doneExamsName.is_open()) {
        doneExamsName << userName << " " << examName << "\n";
        doneExamsName.close();
    }
}
