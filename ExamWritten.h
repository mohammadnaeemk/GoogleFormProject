// ExamWritten.h file
#ifndef EXAMWRITTEN_H
#define EXAMWRITTEN_H
#include "Exam.h"
class ExamWritten : public Exam
{

private:
public:
    //constructor
    ExamWritten(string examname, int totalScore, int numberquestins, int timenum);

//for build Exam Written
    bool ExamWrittenCreator();
    static void  takeDescriptiveExam(string examName, string userName);
};
#endif