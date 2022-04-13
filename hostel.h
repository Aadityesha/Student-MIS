#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <process.h>

using namespace std;
class Student
{

    char sname[20], fatname[20], motname[20], dept[30], droll[12], year[30], peradd[40], gdname[20], gdadd[40];
    char snum[15], fatnum[15], motnum[15], gdnum[15], dob[15], gender[10];
    int Distance, room_no, floor;
    char hostel_no[4], block, hroll[4];

public:
    void getInfo();
    void roomDetails();
    void addData();
    friend class Admin;
} s;

class Admin
{
    char sname[20], fatname[20], motname[20], dept[30], droll[12], year[30], peradd[40], gdname[20], gdadd[40];
    char snum[15], fatnum[15], motnum[15], gdnum[15], dob[15], gender[10];
    int Distance, room_no, floor;
    char hostel_no[4], block, hroll[4];

public:
    void main_menu();
    void showData();
    void addData();
    void displayInfo();
    void displayInfo1();
    void login();
    void allot();
    void roomDetails();
    void search();
    void update();
    void deleteStudent();
    void fees();
    friend class mess;
    friend class Student;
} h;

class mess
{
    char hroll[4], month[20];
    int extra, bill, diets;

public:
    void addBill();
    void getBill();
    void showBill();
    void displayBill();
    void deleteBill();
    friend class Admin;
} m;

void Student::getInfo()
{
    cout << setw(70);
    cout << "\n\n\t\t\t Welcome to Student Information Module" << endl;
    cout << "\n";

    cin.ignore();
    cout << " Student's Name:-"
         << "\t\t";
    cin.getline(sname, 20);
    cout << " Father's Name:-"
         << "\t\t";
    cin.getline(fatname, 20);
    cout << " Mother's Name:-"
         << "\t\t";
    cin.getline(motname, 20);
    cout << " Date of Birth(dd/mm/yy):-"
         << "\t\t";
    cin.getline(dob, 15);
    cout << " Gender:-"
         << "\t\t";
    cin.getline(gender, 10);
    cout << " Name Of The Department:-\t\t";
    cin.getline(dept, 30);
    cout << " Department Roll No.:-\t\t";
    cin.getline(droll, 12);
    cout << " Enter the year:-"
         << "\t\t";
    cin.getline(year, 30);
    cout << " Permanent Address:-"
         << "\t\t";
    cin.getline(peradd, 20);
    cout << " Name of Local Guardian:-\t";
    cin.getline(gdname, 20);
    cout << " Address Of Local Guardian:-\t";
    cin.getline(gdadd, 30);
    cout << " Student's Mobile Number:-\t";
    cin.getline(snum, 12);
    cout << " Father's Mobile Number:-\t";
    cin.getline(fatnum, 12);
    cout << " Mother's Mobile Number:-\t";
    cin.getline(motnum, 12);
    cout << " Guardian's Mobile Number:-\t";
    cin.getline(gdnum, 12);
    cout << "Distance of University from Your Permanent Address(in Kilometres):-\t";
    cin >> Distance;

    system("pause");
}
void Student::addData()
{
    ofstream fout;
    fout.open("Temp.txt", ios::binary | ios::out | ios::app);
    s.getInfo();
    fout.write((char *)&s, sizeof(s));
    fout.close();
    cout << "\n\nData Successfully Saved to File....\n";
}

void Admin::showData()
{
    ifstream fin;
    fin.open("Record.txt", ios::in | ios::binary);
    while (fin.read((char *)&s, sizeof(s)))
    {
        h.displayInfo();
    }
    fin.close();
    cout << "\n\nData Reading from File Successfully Done....\n";
}

void Admin::displayInfo1()
{
    cout << "\n\n.......Student Details......\n";
    cout << " Student's Name:-            " << s.sname << endl;
    cout << " Father's Name:-             " << s.fatname << endl;
    cout << " Mother's Name:-             " << s.motname << endl;
    cout << " Date Of Birth:-             " << s.dob << endl;
    cout << " Gender:-                    " << s.gender << endl;
    cout << " Name Of The Department:-    " << s.dept << endl;
    cout << " Department ID:-             " << s.droll << endl;
    cout << " Enter the year:-            " << s.year << endl;
    cout << " Permanent Address:-         " << s.peradd << endl;
    cout << " Name of Local Guardian:-    " << s.gdname << endl;
    cout << " Address Of Local Guardian:- " << s.gdadd << endl;
    cout << " Student's Mobile Number:-   " << s.snum << endl;
    cout << " Father's Mobile Number:-    " << s.fatnum << endl;
    cout << " Mother's Mobile Number:-    " << s.motnum << endl;
    cout << " Guardian's Mobile Number:-  " << s.gdnum << endl;
    cout << " Distance of University from \nYour Permanent Address(in Kilometres):-" << s.Distance << endl;
}

void Admin::displayInfo()
{
    cout << "\n\n.......Student Details......\n";
    cout << " Student's Name:-            " << s.sname << endl;
    cout << " Father's Name:-             " << s.fatname << endl;
    cout << " Mother's Name:-             " << s.motname << endl;
    cout << " Date Of Birth:-             " << s.dob << endl;
    cout << " Gender:-                    " << s.gender << endl;
    cout << " Name Of The Department:-    " << s.dept << endl;
    cout << " Department ID:         " << s.droll << endl;
    cout << " Enter the year:-            " << s.year << endl;
    cout << " Permanent Address:-         " << s.peradd << endl;
    cout << " Name of Local Guardian:-    " << s.gdname << endl;
    cout << " Address Of Local Guardian:- " << s.gdadd << endl;
    cout << " Student's Mobile Number:-   " << s.snum << endl;
    cout << " Father's Mobile Number:-    " << s.fatnum << endl;
    cout << " Mother's Mobile Number:-    " << s.motnum << endl;
    cout << " Guardian's Mobile Number:-  " << s.gdnum << endl;
    cout << " Distance of University from \nYour Permanent Address(in Kilometres):-" << s.Distance << endl;
    cout << "\n\n........Hostel Details........\n";
    cout << " Hostel No.:-    " << s.hostel_no << endl;
    cout << " Hostel Roll No.:-    " << s.hroll << endl;
    cout << " Block:-  " << s.block << endl;
    cout << " Floor No.:-" << s.floor << endl;
    cout << " Room No.:-" << s.room_no << endl;
}

void Admin::allot()
{
    ifstream fin;
    fin.open("Temp.txt", ios::in | ios::binary);
    ofstream fout;
    fout.open("Record.txt", ios::binary | ios::out | ios::app);

    while (fin.read((char *)&s, sizeof(s)))
    {
        system("cls");
        h.displayInfo1();
        cout << "\nPress Enter key to Enter Data OR 0 to Exit";
        char g;
        g = getch();
        if (g == '0')
        {
            cout << endl;
            return;
        }
        s.roomDetails();
        fout.write((char *)&s, sizeof(s));
    }
    fin.close();
    fout.close();
    remove("Temp.txt");
}

void Student::roomDetails()
{
    system("cls");
    cout << "\n\n\t\t\t Welcome to Room Allotment Section" << endl;
    cout << "\n";
    cout << "Enter Hostel No.:-         ";
    cin >> s.hostel_no;
    cout << "Enter Hostel Roll No.:-    ";
    cin >> s.hroll;
    cout << "Enter Block:-              ";
    cin >> s.block;
    cout << "Floor No.:-                ";
    cin >> s.floor;
    cout << "Enter Room No:-            ";
    cin >> s.room_no;
}

void Admin::search()
{
    char r[20];
    cout << "\n\nEnter Your Department or Hostel Roll No.:  ";
    cin >> r;
    int flag = 0;
    ifstream inf, fin;
    inf.open("Record.txt", ios::binary | ios::in | ios::app);
    fin.open("Temp.txt", ios::binary | ios::in | ios::app);

    while (inf.read((char *)&h, sizeof(h)))
    {
        if (stricmp(r, h.hroll) == 0 || stricmp(r, h.droll) == 0)
        {
            h.displayInfo();
            flag = 1;
        }
    }
    while (fin.read((char *)&h, sizeof(h)))
    {
        if (stricmp(r, h.droll) == 0)
        {
            h.displayInfo1();
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "\n\nStudent with Roll No. " << r << " not found.\n\n";
    }
}

void Admin::deleteStudent()
{
    ifstream inf;
    inf.open("Record.txt", ios::binary | ios::in | ios::app);
    ofstream outf;
    outf.open("Temp_delete.txt", ios::binary | ios::out | ios::app);
    char r[10];
    int flag = 0;
    cout << "\nEnter Hostel Roll No.:- ";
    cin >> r;
    while (inf.read((char *)&h, sizeof(h)))
    {
        if (stricmp(r, h.hroll) == 0)
        {
            cout << "\n The following Student data will be deleted: \n\n";
            h.displayInfo();
            flag = 1;
        }
        else
        {
            outf.write((char *)&h, sizeof(h));
        }
    }
    inf.close();
    outf.close();
    if (flag == 0)
    {
        cout << "\nStudent with Roll No. " << r << " not found";
    }
    remove("Record.txt");
    rename("Temp_delete.txt", "Record.txt");
}

void Admin::update()
{
    int flag = 0, pos;
    char r[10];
    fstream fio;
    fio.open("Record.txt", ios::in | ios::out | ios::binary);

    cout << "Enter Hostel Roll Number you want to Modify : ";
    cin >> r;

    while (fio.read((char *)&s, sizeof(s)))
    {
        pos = fio.tellg();
        if (stricmp(r, h.hroll) == 0)
        {
            cout << "The Following Admission No. " << r << " will be modified with new data:\n";
            h.displayInfo();
            cout << "\n\nNow Enter the New Details....\n";
            s.getInfo();
            fio.seekg(pos - sizeof(h));
            fio.write((char *)&h, sizeof(h));
            flag++;
        }
    }
    fio.close();

    if (flag == 0)
        cout << "The Admission No. " << r << " not found....\n\n";
}

void Admin::fees()
{
    int count = 0, dietBill = 0;
    ifstream fin, inf;
    fin.open("Record.txt", ios::in | ios::binary);
    inf.open("Mess.txt", ios::in | ios::binary);
    while (fin.read((char *)&h, sizeof(h)))
    {
        count++;
    }
    while (inf.read((char *)&m, sizeof(m)))
    {
        dietBill += m.bill;
    }
    fin.close();
    cout << "\n\n\t\t\t\t...........Fees & Stats Module............\n\n\n\n";
    cout << "\t\t\t\tTotal No. of Students:-       " << count << endl;
    cout << "\t\t\t\tTotal Fees in Account:-       " << count * 19550 << endl;
    cout << "\t\t\t\tTotal Mess Security:-         " << count * 6000 << endl;
    cout << "\t\t\t\tTotal Mess Bill:-             " << dietBill << endl
         << endl;
}

void mess::addBill()
{
    ofstream fout;
    fout.open("Mess.txt", ios::binary | ios::out | ios::app);
    m.getBill();
    fout.write((char *)&m, sizeof(m));
    fout.close();
    cout << "\n\nData Successfully Saved to File....\n";
}

void mess::getBill()
{
    cout << "\n\n\t\t\t...........Mess Information Module............\n\n";
    ifstream fin;
    fin.open("Record.txt", ios::in | ios::binary);
    int flag = 0;
    cout << "Enter Hostel Roll No.:-     ";
    cin >> hroll;
    while (fin.read((char *)&h, sizeof(h)))
    {
        if (stricmp(hroll, h.hroll) == 0)
        {
            cout << "Enter Month:-               ";
            cin >> month;
            cout << "Enter Meals:-               ";
            cin >> diets;
            cout << "Enter Extras:-              ";
            cin >> extra;
            bill = (diets * 32) + extra;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "\nNo Student with Roll No. " << hroll << " in records.";
    }
}

void mess::showBill()
{
    ifstream fin;
    fin.open("Mess.txt", ios::in | ios::binary);
    char r[5];
    int flag = 0;
    cout << "\nEnter Hostel Roll No.:-     ";
    cin >> r;
    while (fin.read((char *)&m, sizeof(m)))
    {
        if (stricmp(m.hroll, r) == 0)
        {
            m.displayBill();
            flag = 1;
        }
    }
    fin.close();
    if (flag == 0)
    {
        cout << "\n\nNo records for roll no. " << r;
    }
    cout << "\n\nData Reading from File Successfully Done....\n";
}

void mess::displayBill()
{
    cout << "\n\n\t\t\t======" << month << "======\n\n";
    cout << "Meals:          " << diets << endl;
    cout << "Extras:         " << extra << endl;
    cout << "Bill:           " << bill << endl;
}

void mess::deleteBill()
{
    ifstream inf;
    inf.open("Mess.txt", ios::binary | ios::in | ios::app);
    ofstream outf;
    outf.open("Temp_Mess.txt", ios::binary | ios::out | ios::app);
    char r[10];
    int flag = 0;
    cout << "\nEnter Hostel Roll No.:- ";
    cin >> r;
    while (inf.read((char *)&m, sizeof(m)))
    {
        if (stricmp(r, m.hroll) == 0)
        {
            cout << "\n The following Student data will be deleted: \n\n";
            m.displayBill();
            flag = 1;
        }
        else
        {
            outf.write((char *)&m, sizeof(m));
        }
    }
    inf.close();
    outf.close();
    if (flag == 0)
    {
        cout << "\nStudent with Roll No. " << r << " not found";
    }
    remove("Mess.txt");
    rename("Temp_Mess.txt", "Mess.txt");
}

void Admin::main_menu()
{

    system("cls");

    cout << endl;

    cout << "\n\n\t\t\t 0. Exit" << endl;
    cout << "\n\n\t\t\t 1. Allot Room" << endl;
    cout << "\n\n\t\t\t 2. View Student Information" << endl;
    cout << "\n\n\t\t\t 3. Search Student" << endl;
    cout << "\n\n\t\t\t 4. Delete Student" << endl;
    cout << "\n\n\t\t\t 5. Update Student Data" << endl;
    cout << "\n\n\t\t\t 6. Add Mess Information" << endl;
    cout << "\n\n\t\t\t 7. View Mess Information" << endl;
    cout << "\n\n\t\t\t 8. Delete Mess Information" << endl;
    cout << "\n\n\t\t\t 9. View Fees and Stats" << endl;
    int choice;
    cout << "\n\n\t\t\t Enter your choice: ";
    cin >> choice;

    if (choice == 0)
    {
        system("cls");
        return;
    }
    else if (choice == 1)
    {
        system("cls");
        h.allot();
        system("pause");
        main_menu();
    }
    else if (choice == 2)
    {
        system("cls");
        h.showData();
        system("pause");
        main_menu();
    }
    else if (choice == 3)
    {
        system("cls");
        h.search();
        system("pause");
        main_menu();
    }
    else if (choice == 4)
    {
        system("cls");
        h.deleteStudent();
        system("pause");
        main_menu();
    }
    else if (choice == 5)
    {
        system("cls");
        h.update();
        system("pause");
        main_menu();
    }
    else if (choice == 6)
    {
        system("cls");
        m.addBill();
        system("pause");
        main_menu();
    }
    else if (choice == 7)
    {
        system("cls");
        m.showBill();
        system("pause");
        main_menu();
    }
    else if (choice == 8)
    {
        system("cls");
        m.deleteBill();
        system("pause");
        main_menu();
    }
    else if (choice == 9)
    {
        system("cls");
        h.fees();
        system("pause");
        main_menu();
    }
}

void Admin::login()
{
    char user[30], pass[30];
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t\tEnter UserName: ";
    cin >> user;
    cout << "\n\n\t\t\t\t\tEnter Password: ";
    cin >> pass;
    if (strcmp(user, "studentmis3") == 0 && strcmp(pass, "studentmis3") == 0)
    {
        main_menu();
    }
    else
    {
        cout << "\n\n\t\t\tIncorrect Username or Password. Press any key to try again!";
        getch();
        system("cls");
        login();
    }
}

int menu()
{
    Admin h1;
    mess m1;
    Student s1;
    system("cls");
    cout << "\n\n\t\t===========================SJCE HOSTEL MANAGEMENT SYSYTEM ==========================\n\n";
    cout << "\n\n\t\t1. Administration Login\n";
    cout << "\n\n\t\t2. Enter Data To Register\n";
    cout << "\n\n\t\t3. View Your Data\n";
    cout << "\n\n\t\t4. View Mess Info\n";
    int choice;
    cout << "\n\n\t\tEnter Your Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        system("cls");
        h1.login();
        system("pause");
        menu();
    }
    else if (choice == 2)
    {
        system("cls");
        s1.addData();
        system("pause");
        menu();
    }
    else if (choice == 3)
    {
        system("cls");
        h1.search();
        system("pause");
        menu();
    }
    else if (choice == 4)
    {
        system("cls");
        m1.showBill();
        system("pause");
        menu();
    }
}
int Hostell()
{
    system("color 3F");
    menu();
    getch();
    return 0;
}