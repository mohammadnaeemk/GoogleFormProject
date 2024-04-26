// ExamTest.h file
#ifndef EXAMTEST_H
#define EXAMTEST_H
#include "Exam.h"
#include <string>

using namespace std;

class ExamTest : public Exam
{

private:

public:

    // variable and function declaration
    ExamTest(string ,int , int ,int );

    bool ExamTestCreator();
    //The output of the following function is the final score of the student's test.
    // The function is for correcting the student's exam
    float Corrector();



};
#endif