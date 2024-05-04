// Master.h file
#ifndef MASTER_H
#define MASTER_H
#include <string>

using namespace std;
class Master
{

private:

public:

    // variable and function declaration
    Master();
    static void ListMaker(string);
    static bool UserNameChecker(string,string,bool);
    static string StudentReturner(string);
};
#endif