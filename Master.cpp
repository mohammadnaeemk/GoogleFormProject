// Master.cpp file
#include "Master.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string masterName;
int masterPassword;

 Master::Master(){}


// Checking the username to avoid duplicates.
 bool Master::UserNameChecker(string adress, string input,bool FLAG) {
    string strCheck1="",strCheck2="",line;
    bool F = false;
    if (FLAG == true) {
        for (int i = input.size() - 1; i >= 0; --i) {
            if (input[i] == ' ') {
                strCheck1 = input.substr(0, i);
                break;
            }
        }
    }
    else
    {
        strCheck1 = input;
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
    tempFile.close();
    return F;
 }

 //Returning student information using its username.
 string Master::StudentReturner(string User)
 {
     string strCheck1="",strCheck2="",line;
     strCheck1 = User;
     fstream file;
     file.open("StudentsDB.txt",ios::in);
     if (file.is_open()){
         while (getline(file,line)) {
             for (int i = line.size() - 1; i >= 0; --i) {
                 if (line[i] == ' ') {
                     strCheck2 = line.substr(0, i);
                     if (strCheck1==strCheck2)
                     {
                         file.close();
                         return line;
                         break;
                     }

                 }
             }
         }
     }
     return line;
 }


//Student list maker
void Master::ListMaker(string listName)
{
    string userName;
    bool functionFlag= true;

        while (true)
        {
            cout<<"--------------------------------------------------------------------------------\n";
            cout<<"Please enter the usernames of the students you want to add(Enter 'exit' to exit) :  \n";
            getline(cin>>ws,userName);
            if (userName != "exit") {
                if (Master::UserNameChecker("StudentsDB.txt", userName, false)) {
                    fstream list;
                    list.open("StudentLists/"+listName+".txt",ios::app);
                    if (list.is_open()){
                        list<<StudentReturner(userName)<<endl;
                        list.close();
                        cout<<"The student was added to the list.\n";
                    }
                }
                else
                {
                    cout << "Your desired student was not found!\n";
                }
            }
            else{break;}
        }
}



