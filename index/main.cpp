#include <bits/stdc++.h>
using namespace std;
#include "FCFS.cpp"
#include "SJF.cpp"
#include "SRJF.cpp"
#include "RR.cpp"
#include "Priority.cpp"

int main()
{
    int choice;
    cout << "Enter 1 for FCFS\nEnter 2 for SJF\nEnter 3 for SRJF\n";
    cout << "Enter your choice: " << endl;
    cin >> choice;
    //1 is FCFS
    //2 is SJF
    //3 is SRJF
    //4 is RR
    switch (choice)
    {
    case 1:
        FCFS();
        break;
    case 2:
        SJF();
        break;
    case 3:
        SRJF();
        break;
    case 4:
        RR();
        break;
    case 5:
        Priority();
        break;
    default:
        break;
    }
    return 0;
}