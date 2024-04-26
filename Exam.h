// Exam.h file
#ifndef EXAM_H_INCLUDED
#define EXAM_H_INCLUDED
#include <string>

using namespace std;
class Exam
{
protected:
    int timeM;
    int numberOfQuestions;
    int score;
    string examName;
public:

    //تابع زیر تنظیم کننده نمره است
    void SetScore(float);


    // constructor
    Exam(string,int ,int ,int);

};
#endif