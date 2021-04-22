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
int FIFO(){
    int FIFO_i,FIFO_j,FIFO_k,FIFO_n,FIFO_m,FIFO_sum=0,FIFO_x,FIFO_y,FIFO_h;
    cout<<"Enter total number of tracks on the disk: ";
    cin>>FIFO_m;
    cout<<"Enter total number of requests: ";
    cin>>FIFO_n;
    cout<<"Please enter the requests!"<<endl;
    //a vector of size n
    vector <int> a(FIFO_n);
    for(FIFO_i=0;FIFO_i<FIFO_n;FIFO_i++){
        cout<<"Enter the request "<<FIFO_i+1<<": ";
        cin>>a[FIFO_i];
        if(a[FIFO_i]>=FIFO_m)
        {
             cout<<"Error! Unknown position of track "<<a[FIFO_i]<<" on the disk \n";
        }
    }
    cout<<"Enter  read/write head position: ";
    cin>>FIFO_h;
    // head position is at h in the beginning
    int temp=FIFO_h;
    cout<<temp;
    for(FIFO_i=0;FIFO_i<FIFO_n;FIFO_i++){
            if(a[FIFO_i]>=FIFO_m)
            continue;
        cout<<" -> "<<a[FIFO_i]<<' ';
        // calculating the difference for the read/write head movement
        FIFO_sum+=abs(a[FIFO_i]-temp);
        // head is now at the next I/O request
        temp=a[FIFO_i];
    }
    cout<<'\n';
    cout<<"Total seek time = "<< FIFO_sum<<"\n";
    return 0;
}
