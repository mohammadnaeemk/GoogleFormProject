// ExamTest.cpp file
#include "ExamTest.h"
#include "Exam.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//constructor
ExamTest::ExamTest(string examname, int totalScore, int numberquestins, int timenum) : Exam(examname,totalScore, numberquestins, timenum) {}

bool ExamTest::ExamTestCreator() {
    fstream ExamFile;
    string fileName = "";

    fileName=examName + "Test";
    fileName = "ExamList/"+ fileName + ".txt";
    ExamFile.open(fileName, ios::out);//creat test exam file
    ExamFile.close();
    fstream ExamFileEdit;
    ExamFileEdit.open(fileName,ios::app);
    ExamFileEdit<< "Number of questions : " << numberOfQuestions << endl;
    ExamFileEdit << "Time : " <<timeM << endl;
    ExamFileEdit<< "Total score : " << score << endl;

    for (int i = 1; i <= numberOfQuestions ; ++i) {
        string text=to_string(i),temp="";
        cout<<"Please enter the text of question "<< i <<" : \n";
        getline(cin>>ws,temp);

        text += ") ";
        text = text + temp;
        ExamFileEdit << text << endl << "\t";
        cout << "Please enter 4 answer options of your test:\n";
        for(int j = 1; j <= 4; j++){
            string test = "";
            string tnumber = "";
            tnumber = to_string(j) + ".";
            getline(cin >> ws, test);
            ExamFileEdit << tnumber << test << " \t";
        }
        cout << "Enter the correct answer of question " << i << ": " << endl;
        string answer = "";
        string _text = "\n\tCorrect answer: ";
        getline(cin >> ws, answer);
        ExamFileEdit << _text << answer << endl << endl;
    }
    ExamFileEdit.close();

    fstream Examname; //adding exam name to ExamsList.txt
    Examname.open("ExamsName.txt", ios::app);
    examName += "Test";
    Examname << examName << endl;
    Examname.close();

    return true;
}
//The output of the following function is the final score of the student's test.
// The function is for correcting the student's exam
float Corrector()
{

}