#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
#include "../CPU_scheduling/FCFS.cpp"
#include "../CPU_scheduling/SJF.cpp"
#include "../CPU_scheduling/SRJF.cpp"
#include "../CPU_scheduling/RR.cpp"
#include "../CPU_scheduling/Priority.cpp"
#include "../CPU_scheduling/LRF.cpp"
#include "../CPU_scheduling/LRJF.cpp"
#include "../MFT/MVT.cpp"
#include "../MFT/MFT.c"
#include "../'Disk Scheduling'/FIFO.cpp"
#include "../'Disk Scheduling'/CLOOK.cpp"
#include "../'Disk Scheduling'/CSCAN.cpp"
#include "../'Disk Scheduling'/LOOK.cpp"
#include "../'Disk Scheduling'/SCAN.cpp"
int main()
{
    bool ok = true;
    while (ok)
    {
        int choice;
        //system("CLS");
        cout << "1. Scheduling Algorithms\n2. Partitioning algorithms(MVT/MFT)\n3. Disk scheduling";
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            //system("CLS");
            cout << "Enter 1 for FCFS\nEnter 2 for SJF\nEnter 3 for SRJF\nEnter 4 for Round Robin\nEnter 5 for Prioity\n";
            cout << "Enter your option: ";
            int sched_choice;
            cin >> sched_choice;
            switch (sched_choice)
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
            case 6:
                LRF();
                break;
            case 7:
                LRJF();
            default:
                break;
            }
            //system("PAUSE");
            break;
        case 2:
            //system("CLS");
            cout << "Do you want to use (1)MVT or (2)MFT parititioning?\nEnter option: ";
            int partition_choice;
            cin >> partition_choice;
            if (partition_choice == 1)
                MVT();
            else if (partition_choice == 2)
                MFT();
            //system("PAUSE");
            break;
        case 3:
            int disk_choice;
            cout << "1.FIFO" << endl;
            cout << "2.SCAN" << endl;
            cout << "3.CSCAN" << endl;
            cout << "4.LOOK" << endl;
            cout << "5.CLOOK" << endl;
            cout << "Enter your choice of disk scheduling algorithms(enter 0 to exit): ";
            cin >> disk_choice;
            switch (disk_choice)
            {
            case 1:
                FIFO();
                break;
            case 2:
                SCAN();
                break;
            case 3:
                CSCAN();
                break;
            case 4:
                LOOK();
                break;
            case 5:
                CLOOK();
                break;
            default:
                cout << "Please enter a valid choice!" << endl;
            }
        default:
            ok = false;
        }
    }
    return 0;
}