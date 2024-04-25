#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Master.h"
#include "Student.h"

using namespace std;

int main() {
menu:
    cout << "Login as master or student(press 1 or 2 for login and 3 for exit)\n "
            "1. Student\n "
            "2. Master\n "
            "3. exit\n";
    int op = 0;
    cin >> op;
    if(op == 1){
        cout << "Please enter your username and password: ";
        string input;
        getline(cin >> ws, input);
        fstream studentfile;
        studentfile.open("StudentsDB.txt", ios::in);//read from student file
        if(studentfile.is_open()){
            string line;
            while(getline(studentfile, line)){ //search for student
                if(line == input){
                    cout << "You have successfully logged in as student\n";
                }
                else{
                    cout << "Invalid username or password!\n\n";
                    goto menu; //goes to menu page
                }
            }
            studentfile.close();
        }

    }
    if(op == 2){
        cout << "Please enter your username and password: ";
        string input;
        getline(cin >> ws, input);
        fstream masterfile;
        masterfile.open("MastersDB.txt", ios::in);//read from master file
        if(masterfile.is_open()){
            string line;
            while(getline(masterfile, line)){ //search for master
                if(line == input){
                    cout << "You have successfully logged in as master\n";
                }
                else{
                    cout << "Invalid username or password!\n\n";
                    goto menu; //goes to menu page
                }
            }
            masterfile.close();
        }

    }
    if(op == 3){
        exit(0);
    }

    return 0;
}
