// Exam.cpp file
#include "Exam.h"
#include <iostream>
#include <string>
using namespace std;
string exameName;
int timeM;
int numberOfQuestions;
int score;

//constructor
Exam::Exam(string name,int numberQ,int timeNumber)
{
    exameName=name;
    numberOfQuestions=numberQ;
    timeM=timeNumber;
}




