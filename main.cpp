#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Master.h"
#include "Student.h"

using namespace std;

int main() {
    bool flag= true;
    while(flag) {

        cout << "Login as master or student or creat account (press 1 or 2 or 3 for login and 0 for exit)\n"
                " 0. exit\n "
                "1. Student\n "
                "2. Master\n "
                "3. Register\n";
        int op = 0;
        cin >> op;
        if (op == 1) {
            cout << "Please enter your username and password(Enter 0 to return to the main menu):";
            string input = "";
            getline(cin >> ws, input);
            if (input=="0")
            {
                continue;//back to menu
            }
            fstream studentfile;
            studentfile.open("StudentsDB.txt", ios::in);//read from student file
            if (studentfile.is_open()) {
                string line;
                while (getline(studentfile, line)) { //search for student
                    if (line == input) {
                        cout << "You have successfully logged in as student\n";
                    } else {
                        cout << "Invalid username or password!\n\n";
                        continue; //goes to menu page
                    }
                }
                studentfile.close();
            }

        }
        if (op == 2) {
            cout << "Please enter your username and password(Enter 0 to return to the main menu):";
            string input = "";
            getline(cin >> ws, input);
            if (input=="0")
            {
                continue; //Back to menu
            }
            fstream masterfile;
            masterfile.open("MastersDB.txt", ios::in);//read from master file
            if (masterfile.is_open()) {
                string line;
                while (getline(masterfile, line)) { //search for master
                    if (line == input) {
                        cout << "You have successfully logged in as master\n";
                    } else {
                        cout << "Invalid username or password!\n\n";
                        continue; //goes to menu page
                    }
                }
                masterfile.close();
            }

        }
        if (op == 3) {
            string op2;
            cout << "Are you master or student?(Enter 0 to return to the main menu) ";
            cin >> op2;
            if (op2 == "master") {
                cout << "Please enter a username and a password:";
                string input = "";
                getline(cin >> ws, input);
                fstream mastercrfile;
                mastercrfile.open("MastersDB.txt", ios::app); //append to master file
                if (mastercrfile.is_open()) {
                    mastercrfile << endl << input;
                    cout << "\nYou have successfully created an account.\n";
                    mastercrfile.close();
                }
            } else if (op2 == "student") {
                cout << "Please enter a username and a password: ";
                string input = "";
                getline(cin >> ws, input);
                fstream studentcrfile;
                studentcrfile.open("StudentsDB.txt", ios::app); //append to student file
                if (studentcrfile.is_open()) {
                    studentcrfile << endl << input;
                    cout << "\nYou have successfully created an account.\nlogging in...\n";
                    studentcrfile.close();
                }
                cout << "You have successfully logged in as student\n";
            }
            else if (op2=="0")
            {
                continue;
            }
        }
        if (op == 0) {
           flag= false;
        }
    }
    return 0;
}
