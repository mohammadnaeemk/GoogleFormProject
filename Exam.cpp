// Exam.cpp file
#include "Exam.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
Exam::Exam(string name,int totalScore,int numberQ,int timeNumber)
{
    score = totalScore;
    examName=name;
    numberOfQuestions=numberQ;
    timeM=timeNumber;
}




