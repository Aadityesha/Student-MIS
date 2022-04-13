#include <iostream>
#include <fstream>
#include <windows.h>
#include <dos.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "hostel.h"
#include "canteen.h"
#include "attendance.h"

using namespace std;

int main()
{
    system("color 3F");
    cout << "\t" << char(201);
    for (int i = 0; i < 47; i++)
    {
        cout << char(205);
    }
    cout << char(187) << endl;
    cout << "\t" << char(186) << "                                               " << char(186) << endl;
    cout << "\t" << char(186) << "                                               " << char(186) << endl;
    cout << "\t" << char(186) << "                STUDENT MIS 3                  " << char(186) << endl;
    cout << "\t" << char(186) << "                                               " << char(186) << endl;
    cout << "\t" << char(186) << "                                               " << char(186) << endl;
    cout << "\t" << char(200);
    for (int i = 0; i < 47; i++)
    {
        cout << char(205);
    }
    cout << char(188) << endl;
    cout << "\n\n";
    cout << "\tFunctionalities of the MIS:\n\n\n";
    cout << "\t1. Hostel Management System\n\n";
    cout << "\t2. Attendance Management System\n\n";
    cout << "\t3. Canteen Management System\n\n";
    int flag = 1;
    cout << "Enter the key corresponding to the system you want to use: \n\t";
    int a;
    while (flag)
    {
        cin >> a;
        switch (a)
        {
        case 1:
            Hostell();
            break;
        case 2:
            Attendance();
            break;
        case 3:
            Canteen();
            break;
        case 0:
            flag = 0;
            break;
        default:
            cout << "Enter a valid choice\n";
        }
    }
    return 0;
}