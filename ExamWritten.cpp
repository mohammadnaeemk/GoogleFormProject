// ExamWritten.cpp file
#include "ExamWritten.h"
#include "Exam.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//constructor
ExamWritten::ExamWritten(string examname, int totalScore, int numberquestins, int timenum) : Exam(examname,totalScore, numberquestins, timenum) {}


//for build Exam Written
bool ExamWritten::ExamWrittenCreator()
{
    fstream ExamFile;
     string fileName="";

    fileName=examName;
    fileName +=".txt";
    ExamFile.open(fileName, ios::out);//read from student file
    fileName = "Exams/" + fileName;
    ExamFile.close();
    fstream ExamFileEdit;
    ExamFileEdit.open(fileName,ios::app);
    ExamFileEdit<<numberOfQuestions;
    ExamFileEdit<<"\n";
    ExamFileEdit<<timeM;
    ExamFileEdit<<"\n";
    ExamFileEdit<<score;
    ExamFileEdit<<"\n";

    for (int i = 1; i <= numberOfQuestions ; ++i) {
        string text=to_string(i),temp="";
        cout<<"Please enter the text of question "<< i <<" : \n";
        getline(cin>>ws,temp);

        text += ") ";
        text = text+ temp + "\n";
        ExamFileEdit<<text;
    }
    ExamFileEdit.close();

    return true;
}

