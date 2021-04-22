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
#include "../CPU_scheduling/HRRN.cpp"
#include "../MFT/MVT.cpp"
#include "../MFT/MFT.c"
#include "../Disk_Scheduling/FIFO.cpp"
#include "../Disk_Scheduling/CLOOK.cpp"
#include "../Disk_Scheduling/CSCAN.cpp"
#include "../Disk_Scheduling/SSTF.c"
#include "../Disk_Scheduling/LOOK.cpp"
#include "../Disk_Scheduling/SCAN.cpp"
#include "../Syncronization/dp.c"
#include "../Syncronization/pc.c"
#include "../Syncronization/rw.c"
#include "../Bankers_Algorithm/bankers.h"
#include "../Page_Replacement/PageReplacement.h"

int main()
{
    bool ok = true;
    while (ok)
    {
        int choice;
        system("CLS");
        cout << "1. Scheduling Algorithms\n2. Partitioning algorithms(MVT/MFT)\n3. Disk scheduling\n4. Synchronization Algorithms\n5. Bankers Algo.\n6. Page Replacement\n";
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "Enter 1 for FCFS\nEnter 2 for SJF\nEnter 3 for SRJF\nEnter 4 for Round Robin\nEnter 5 for Prioity\n";
            cout << "Enter 6 for LRF\n Enter 7 for LRJF\n Enter 8 for HRRN\n";
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
                break;
            case 8:
                HRRN();
                break;
            default:
                break;
            }
            system("PAUSE");
            break;
        case 2:
            system("CLS");
            cout << "Do you want to use (1)MVT or (2)MFT parititioning?\nEnter option: ";
            int partition_choice;
            cin >> partition_choice;
            if (partition_choice == 1)
                MVT();
            else if (partition_choice == 2)
                MFT();
            system("PAUSE");
            break;
        case 3:
            system("CLS");
            int disk_choice;
            cout << "1.FIFO" << endl;
            cout << "2.SCAN" << endl;
            cout << "3.CSCAN" << endl;
            cout << "4.LOOK" << endl;
            cout << "5.CLOOK" << endl;
            cout << "6.SSTF" << endl;
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
            case 6:
                SSTF();
                break;
            default:
                cout << "Please enter a valid choice!" << endl;
            }
            system("PAUSE");
            break;
        case 4:
            int sync_choice;
            system("CLS");
            cout << "1. Readers Writers\n2. Producer Consumers\n3. Diners Philosiphers\nEnter option: ";
            cin >> sync_choice;
            switch (sync_choice)
            {
            case 1:
                system("CLS");
                RW();
                break;
            case 2:
                system("CLS");
                PC();
                break;
            case 3:
                system("CLS");
                DP();
                break;
            default:
                break;
            }
            system("PAUSE");
            break;
        case 5:
            system("CLS");
            Bankers();
            system("PAUSE");
            break;
        case 6:
            system("CLS");
            PAGE();
            system("PAUSE");
            break;
        default:
            ok = false;
        }

        
    }
    return 0;
}