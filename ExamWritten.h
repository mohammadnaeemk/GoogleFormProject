// ExamWritten.h file
#ifndef EXAMWRITTEN_H
#define EXAMWRITTEN_H
#include "Exam.h"
class ExamWritten : public Exam
{

private:

public:

    // variable and function declaration
    ExamWritten(string , int , int );

    ExamWritten(string examname, int totalScore, int numberquestins, int timenum);
};
#endif