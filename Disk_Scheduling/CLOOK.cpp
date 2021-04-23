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
int CLOOK()
{
    int clook_i, clook_k, clook_n, clook_m, clook_sum = 0, clook_h;
    cout << "Enter total number of tracks on the disk: ";
    cin >> clook_m;
    cout << "Enter total number of requests: ";
    cin >> clook_n;
    cout << "Please enter the requests!" << endl;
    vector<int> a(clook_n), l;
    for (clook_i = 0; clook_i < clook_n; clook_i++)
    {
        cout << "Enter the request " << clook_i + 1 << ": ";
        cin >> a[clook_i];
        if (a[clook_i] >= clook_m)
        {
            cout << "Error! Unknown position of track " << a[clook_i] << " on the disk \n";
        }
    }
    cout << "Enter read/write head position: ";
    cin >> clook_h;
    a.push_back(clook_h);
    sort(a.begin(), a.end());
    for (clook_i = 0; clook_i < a.size(); clook_i++)
    {
        if (clook_h == a[clook_i])
            break;
    }
    clook_k = clook_i;
    if (clook_k < clook_n / 2)
    {
        for (clook_i = clook_k; clook_i < a.size(); clook_i++)
        {
            l.push_back(a[clook_i]);
        }
        for (clook_i = 0; clook_i < clook_k; clook_i++)
        {
            l.push_back(a[clook_i]);
        }
        //"Here,Read/Write head is moving towards right side(services requests on its way) , reaches "0"  and goes to the extreme position
        // then reverses its direction(services requests on its way).
        cout << "Here,Read/Write head is moving towards right side and reverses its direction afterwards!" << endl;
    }
    else
    {
        for (clook_i = clook_k; clook_i >= 0; clook_i--)
        {
            l.push_back(a[clook_i]);
        }
        for (clook_i = a.size() - 1; clook_i > clook_k; clook_i--)
        {
            l.push_back(a[clook_i]);
        }
        //"Here,Read/Write head is moving towards left side(services requests on its way) , reaches "0"  and goes to the extreme position
        // then reverses its direction(services requests on its way).
        cout << "Here,Read/Write head is moving towards left side and reverses its direction afterwards!" << endl;
    }
    int temp = l[0];
    cout << temp;
    for (clook_i = 1; clook_i < l.size(); clook_i++)
    {
        if (l[clook_i] >= clook_m)
            continue;
        cout << " -> " << l[clook_i];
        // calculating the difference for the read/write head movement
        clook_sum += abs(l[clook_i] - temp);
        // head is now at the next I/O request
        temp = l[clook_i];
    }
    cout << "\n";
    cout << "Total seek time = " << clook_sum << "\n";
    return 0;
}
