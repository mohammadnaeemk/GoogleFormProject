// Exam.h file
#ifndef EXAM_H_INCLUDED
#define EXAM_H_INCLUDED
#include <string>

using namespace std;
class Exam
{

private:

public:
    //تابع زیر تنظیم کننده نمره است
    void SetScore(float);


    // constructor
    Exam(string,int ,int);

};
#endif