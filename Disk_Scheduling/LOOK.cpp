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
int LOOK(){
    int LOOK_i,LOOK_k,LOOK_n,LOOK_m,LOOK_sum=0,LOOK_h;
    cout<<"Enter total number of tracks on the disk: ";
    cin>>LOOK_m;
    cout<<"Enter total number of requests: ";
    cin>>LOOK_n;
    cout<<"Please enter the requests!"<<endl;
    vector <int> a(LOOK_n),l;
    for(LOOK_i=0;LOOK_i<LOOK_n;LOOK_i++){
        cout<<"Enter the request "<< LOOK_i+1<<": ";
        cin>>a[LOOK_i];
        if(a[LOOK_i]>=LOOK_m)
        {
             cout<<"Error! Unknown position of track "<<a[LOOK_i]<<" on the disk \n";
        }

    }
    cout<<"Enter read/write head position: ";
    cin>>LOOK_h;
    a.push_back(LOOK_h);
    sort(a.begin(),a.end());
    for(LOOK_i=0;LOOK_i<a.size();LOOK_i++){
        if(LOOK_h==a[LOOK_i])
            break;
    }
    LOOK_k=LOOK_i;
    if(LOOK_k<LOOK_n/2){
        for(LOOK_i=LOOK_k;LOOK_i<a.size();LOOK_i++){
            l.push_back(a[LOOK_i]);
        }
        for(LOOK_i=LOOK_k-1;LOOK_i>=0;LOOK_i--){
            l.push_back(a[LOOK_i]);
        }
        cout<<"Here,Read/Write head is moving towards right side and reverses its direction afterwards!"<<endl;
    }
    else{
        for(LOOK_i=LOOK_k;LOOK_i>=0;LOOK_i--){
            l.push_back(a[LOOK_i]);
        }
        for(LOOK_i=LOOK_k+1;LOOK_i<a.size();LOOK_i++){
            l.push_back(a[LOOK_i]);
        }
        cout<<"Here,Read/Write head is moving towards left side and reverses its direction afterwards!"<<endl;
    }
    int temp=l[0];//head h is at the beginning of vector l
    cout<<temp;
    for(LOOK_i=1;LOOK_i<l.size();LOOK_i++){
            if(l[LOOK_i]>=LOOK_m)
            continue;
        cout<<" -> "<<l[LOOK_i];
        // calculating the difference for the read/write head movement
        LOOK_sum+=abs(l[LOOK_i]-temp);
        // head is now at the next I/O request
        temp=a[LOOK_i];
    }
    cout<<"\n";
    cout<<"Total seek time = "<< LOOK_sum<<"\n";
    return 0;
}
