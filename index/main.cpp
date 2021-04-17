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
#include "FCFS.cpp"
#include "SJF.cpp"
#include "SRJF.cpp"
#include "RR.cpp"
#include "Priority.cpp"
#include "../MFT/MVT.cpp"
#include "../MFT/MFT.c"
int main()
{
    bool ok = true;
    while(ok){
        int choice;
        system("CLS");
        cout << "1. Scheduling Algorithms\n2. Partitioning algorithms(MVT/MFT)\n";
        // cout << "Enter 1 for FCFS\nEnter 2 for SJF\nEnter 3 for SRJF\nEnter 4 for Round Robin\nEnter 5 for Prioity\n";
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                system("CLS");
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
                if(partition_choice == 1) MVT();
                else if(partition_choice == 2) MFT();
                system("PAUSE");
                break;
            default: ok = false;
        }

    }
    return 0;
}