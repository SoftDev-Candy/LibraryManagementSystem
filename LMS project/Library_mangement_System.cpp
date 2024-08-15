#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>  // For system and exit functions
#include <limits>   // For numeric limits

using namespace std;

struct Student
{
    string name, dob, uid, fname, mname, address, mail;
    int roll, sem;
    string s1, s2, s3, s4, s5;
    float m1, m2, m3, m4, m5;
};

void welcomeScreen()
{
    system("cls");
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t        =                 WELCOME TO                =";
    cout << "\n\t\t\t\t        =               Student Record              =";
    cout << "\n\t\t\t\t        =                 MANAGEMENT                =";
    cout << "\n\t\t\t\t        =                   SYSTEM                  =";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    cout << "\n\t\t\t\t\t\t\tLoading data";
    for (int i = 0; i < 5; i++)
    {
        cout << "  .";
        Sleep(200);
    }
    cout << "\n";
}

void exitScreen()
{
    system("cls");
    cout << "\n\tThank you for using this software." << endl
         << endl;
    cout << "\tDeveloped By:" << endl;
    cout << "\tSwastik, 20BCG1007, 20BCG1-A" << endl;
    exit(0);
}

void addStudent()
{
    system("cls");
    Student s;
    ofstream outfile("report.txt", ios::app | ios::binary);

    cout << "\n\n";
    cout << "\t\t\t\t======= CREATE A REPORT CARD ========\n\n";
    cout << "Enter your full name: ";
    getline(cin >> ws, s.name);
    cout << "Enter your ID number: ";
    getline(cin, s.uid);
    cout << "Enter your roll number: ";
    cin >> s.roll;
    cout << "Enter your father's name: ";
    getline(cin >> ws, s.fname);
    cout << "Enter your mother's name: ";
    getline(cin, s.mname);
    cout << "Enter your date of birth: ";
    getline(cin, s.dob);
    cout << "Enter your address: ";
    getline(cin, s.address);
    cout << "Enter your e-mail: ";
    getline(cin, s.mail);
    cout << "Enter your semester: ";
    cin >> s.sem;

    cout << "Enter subject 1: ";
    getline(cin >> ws, s.s1);
    cout << "Enter marks of " << s.s1 << ": ";
    cin >> s.m1;
    cout << "Enter subject 2: ";
    getline(cin >> ws, s.s2);
    cout << "Enter marks of " << s.s2 << ": ";
    cin >> s.m2;
    cout << "Enter subject 3: ";
    getline(cin >> ws, s.s3);
    cout << "Enter marks of " << s.s3 << ": ";
    cin >> s.m3;
    cout << "Enter subject 4: ";
    getline(cin >> ws, s.s4);
    cout << "Enter marks of " << s.s4 << ": ";
    cin >> s.m4;
    cout << "Enter subject 5: ";
    getline(cin >> ws, s.s5);
    cout << "Enter marks of " << s.s5 << ": ";
    cin >> s.m5;

    outfile.write(reinterpret_cast<const char *>(&s), sizeof(Student));
    outfile.close();
}

void viewReport()
{
    system("cls");
    Student s;
    int rNum;
    cout << "Enter a roll number: ";
    cin >> rNum;

    ifstream fin("report.txt", ios::binary);
    bool recordFound = false;

    while (fin.read(reinterpret_cast<char *>(&s), sizeof(Student)))
    {
        if (rNum == s.roll)
        {
            cout << "Name: " << s.name << endl;
            cout << "UID: " << s.uid << endl;
            cout << "Roll: " << s.roll << endl;
            cout << "Date of birth: " << s.dob << endl;
            cout << "Father's Name: " << s.fname << endl;
            cout << "Mother's Name: " << s.mname << endl;
            cout << "Address: " << s.address << endl;
            cout << "E-mail: " << s.mail << endl;

            cout << "\nMarks" << endl;
            cout << "Marks in " << s.s1 << ": " << s.m1 << endl;
            cout << "Marks in " << s.s2 << ": " << s.m2 << endl;
            cout << "Marks in " << s.s3 << ": " << s.m3 << endl;
            cout << "Marks in " << s.s4 << ": " << s.m4 << endl;
            cout << "Marks in " << s.s5 << ": " << s.m5 << endl;

            recordFound = true;
            break;
        }
    }

    if (!recordFound)
    {
        cout << "Record not found" << endl;
    }

    fin.close();
}

void viewAll()
{
    system("cls");
    Student s;

    ifstream fin("report.txt", ios::binary);
    bool recordFound = false;

    while (fin.read(reinterpret_cast<char *>(&s), sizeof(Student)))
    {
        cout << "Name: " << s.name << endl;
        cout << "UID: " << s.uid << endl;
        cout << "Roll: " << s.roll << endl;
        cout << "Date of birth: " << s.dob << endl;
        cout << "Father's Name: " << s.fname << endl;
        cout << "Mother's Name: " << s.mname << endl;
        cout << "Address: " << s.address << endl;
        cout << "E-mail: " << s.mail << endl;

        cout << "\nMarks" << endl;
        cout << "Marks in " << s.s1 << ": " << s.m1 << endl;
        cout << "Marks in " << s.s2 << ": " << s.m2 << endl;
        cout << "Marks in " << s.s3 << ": " << s.m3 << endl;
        cout << "Marks in " << s.s4 << ": " << s.m4 << endl;
        cout << "Marks in " << s.s5 << ": " << s.m5 << endl;

        recordFound = true;
        cout << "------------------------------------------" << endl;
    }

    if (!recordFound)
    {
        cout << "No record found" << endl;
    }

    fin.close();
}

void modify()
{
    Student s;
    int rNum;
    cout << "Enter your roll number: ";
    cin >> rNum;

    fstream f("report.txt", ios::in | ios::out | ios::binary);
    bool recordFound = false;

    while (f.read(reinterpret_cast<char *>(&s), sizeof(Student)))
    {
        if (s.roll == rNum)
        {
            cout << "Enter your full name: ";
            getline(cin >> ws, s.name);
            cout << "Enter your ID number: ";
            getline(cin, s.uid);
            cout << "Enter your roll number: ";
            cin >> s.roll;
            cout << "Enter your father's name: ";
            getline(cin >> ws, s.fname);
            cout << "Enter your mother's name: ";
            getline(cin, s.mname);
            cout << "Enter your date of birth: ";
            getline(cin, s.dob);
            cout << "Enter your address: ";
            getline(cin, s.address);
            cout << "Enter your e-mail: ";
            getline(cin, s.mail);
            cout << "Enter your semester: ";
            cin >> s.sem;

            cout << "Enter subject 1: ";
            getline(cin >> ws, s.s1);
            cout << "Enter marks of " << s.s1 << ": ";
            cin >> s.m1;
            cout << "Enter subject 2: ";
            getline(cin >> ws, s.s2);
            cout << "Enter marks of " << s.s2 << ": ";
            cin >> s.m2;
            cout << "Enter subject 3: ";
            getline(cin >> ws, s.s3);
            cout << "Enter marks of " << s.s3 << ": ";
            cin >> s.m3;
            cout << "Enter subject 4: ";
            getline(cin >> ws, s.s4);
            cout << "Enter marks of " << s.s4 << ": ";
            cin >> s.m4;
            cout << "Enter subject 5: ";
            getline(cin >> ws, s.s5);
            cout << "Enter marks of " << s.s5 << ": ";
            cin >> s.m5;

            int pos = (-1) * static_cast<int>(sizeof(Student));
            f.seekp(pos, ios::cur);
            f.write(reinterpret_cast<const char *>(&s), sizeof(Student));

            recordFound = true;
            break;
        }
    }

    if (!recordFound)
    {
        cout << "No such record found" << endl;
    }

    f.close();
}

void deleteReport()
{
    Student s;
    int rNum;
    cout << "Enter roll number: ";
    cin
