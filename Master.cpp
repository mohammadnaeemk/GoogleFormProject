// Master.cpp file
#include "Master.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string masterName;
int masterPassword;

 Master::Master(){}

bool Master::ListMaker(string listName)
{
     fstream list;
     list.open("StudentLists/"+listName+".txt",ios::app);
    if (list.is_open()){
        cout<<"";
        while (true)
        {
            break;
        }
    }
}

// Checking the username to avoid duplicates.
 bool Master::UserNameChecker(string adress, string input) {
    string strCheck1="",strCheck2="",line;
    bool F= false;
    for (int i = input.size()-1; i >=0 ; --i) {
        if (input[i] == ' ')
        {
            strCheck1 = input.substr(0,i);
            break;
        }
    }
    fstream tempFile;

    tempFile.open(adress,ios::in);
    if (tempFile.is_open()){
      while (getline(tempFile,line)) {
        for (int i = line.size() - 1; i >= 0; --i) {
            if (line[i] == ' ') {
                strCheck2 = line.substr(0, i);
                if (strCheck1==strCheck2)
                {
                    F= true;
                    break;
                }

            }
        }
      }
    }
    return F;
 }



