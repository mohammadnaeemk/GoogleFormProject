// Master.cpp file
#include "Master.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string masterName;
int masterPassword;

 Master::Master(){}


// Checking the username to avoid duplicates.
 bool Master::UserNameChecker(string adress, string input, bool FLAG) {
    string strCheck1 = "", strCheck2 = "", line;
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

 //------------------------------------------------------------------
  void Master::deactivateStudent(const string& examName,const  string& listName) {
     // باز کردن فایل ورودی برای خواندن
     fstream file;
     file.open(examName, ios::in);

     if (!file.is_open()) {
         cerr << "Error has occurred while opening file!" << endl;
         return;
     }

     // باز کردن فایل موقت برای نوشتن تغییرات
     ofstream outputFile("temp.txt");

     if (!outputFile.is_open()) {
         cerr << "Error opening temporary file." << endl;
         file.close();
         return;
     }

     string line;
     bool studentFound = false; // پرچم برای پیدا کردن نام دانشجو

     // خواندن فایل ورودی خط به خط
     while (getline(file, line)) {
         // جستجوی عبارت "For students of " در خط
         int pos = line.find("For students of ");
         if (pos != string::npos) {
             // بررسی اینکه نام دانشجو بلافاصله بعد از "For students of " باشد
             int namePos = line.find(listName, pos + 16);
             if (namePos == pos + 16) {
                 studentFound = true; // نام دانشجو پیدا شد
                 // پیدا کردن وضعیت فعلی (Active یا Deactive)
                 int conditionPos = line.find(" Condition: Active", namePos + listName.length());
                 if (conditionPos != string::npos) {
                     // وضعیت فعلی Active است
                     cout << "The list " << listName << " is currently Active. Do you want to deactivate it? (yes/no): ";
                 } else {
                     // پیدا کردن وضعیت Deactive
                     conditionPos = line.find(" Condition: Deactive", namePos + listName.length());
                     if (conditionPos != string::npos) {
                         // وضعیت فعلی Deactive است
                         cout << "The list " << listName << " is currently Deactive. Do you want to activate it? (yes/no): ";
                     } else {
                         // اگر وضعیت پیدا نشد، خط را بدون تغییر در فایل موقت می‌نویسیم
                         outputFile << line << '\n';
                         continue; // به خط بعدی بروید
                     }
                 }

                 // گرفتن پاسخ کاربر و تغییر وضعیت بر اساس پاسخ
                 string response;
                 cin >> response;
                 if (response == "yes") {
                     if (line.find(" Condition: Active") != string::npos) {
                         // تغییر وضعیت از Active به Deactive
                         line.replace(conditionPos, 19, " Condition: Deactive");
                         cout<<"Changes applied successfully :) \n";
                     } else {
                         // تغییر وضعیت از Deactive به Active
                         line.replace(conditionPos, 20, " Condition: Active");
                         cout<<"Changes applied successfully :) \n";
                     }
                 }
             }
         }
         // نوشتن خط (تغییر یافته یا اصلی) به فایل موقتی
         outputFile << line << '\n';
     }

     // بستن فایل‌های باز شده
     file.close();
     outputFile.close();

     // جایگزینی فایل اصلی با فایل موقتی
     remove(examName.c_str());
     rename("temp.txt", examName.c_str());

     // اگر نام لیست در هیچ کجای فایل پیدا نشد
     if (!studentFound) {
         cout << "The student " << listName << " was not found in the file." << endl;
     }
 }
 //---------------------------------------------------------

//Student list maker
void Master::ListMaker(string listName)
{
    string userName;
    bool functionFlag = true;

        while (true)
        {
            cout<<"--------------------------------------------------------------------------------\n";
            cout<<"Please enter the usernames of the students you want to add(Enter 'exit' to exit) :  \n";
            getline(cin>>ws,userName);
            if (userName != "exit") {
                if (Master::UserNameChecker("StudentsDB.txt", userName, false)) {
                    fstream list;
                    list.open("StudentLists/" + listName + ".txt",ios::app);
                    if (list.is_open()){
                        list << StudentReturner(userName) << endl;
                        list.close();
                        cout<<"The student was added to the list.\n";
                    }
                }
                else
                {
                    cout << "Your chosen student has not found!\n";
                }
            }
            else
            {
                break;
            }
        }
}



