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
int SCAN(){
    int SCAN_i,SCAN_k,SCAN_n,SCAN_m,SCAN_sum=0,SCAN_h;
    cout<<"Enter total number of tracks on the disk: ";
    cin>>SCAN_m;
    cout<<"Enter total number of requests: ";
    cin>>SCAN_n;
    cout<<"Please enter the requests!"<<endl;
    int tmp[SCAN_n];
    vector <int> a(SCAN_n),b;
    for(SCAN_i=0;SCAN_i<SCAN_n;SCAN_i++){
        cout<<"Enter the request "<<SCAN_i+1<<": ";
        cin>>a[SCAN_i];
        if(a[SCAN_i]>=SCAN_m)
        {
             cout<<"Error! Unknown position of track "<<a[SCAN_i]<<" on the disk \n";
        }
    }
    cout<<"Enter read/write head position: ";
    cin>>SCAN_h;
    int temp=SCAN_h;
    a.push_back(SCAN_h);
    a.push_back(SCAN_m-1);
    a.push_back(0);
  sort(a.begin(),a.end());
    cout<<"\n";
    for(SCAN_i=0;SCAN_i<a.size();SCAN_i++){
        if(SCAN_h==a[SCAN_i])
            break;
    }
    SCAN_k=SCAN_i;
    if(SCAN_k<SCAN_n/2){
        for(SCAN_i=SCAN_k;SCAN_i<a.size();SCAN_i++){
            b.push_back(a[SCAN_i]);
        }
        for(SCAN_i=SCAN_k-1;SCAN_i>=0;SCAN_i--){
            b.push_back(a[SCAN_i]);
        }
        cout<<"Here,Read/Write head is moving towards right side and reverses its direction afterwards!"<<endl;
    }
    else{
        for(SCAN_i=SCAN_k;SCAN_i>=0;SCAN_i--){
            b.push_back(a[SCAN_i]);
        }
        for(SCAN_i=SCAN_k+1;SCAN_i<a.size();SCAN_i++){
            b.push_back(a[SCAN_i]);
        }
        cout<<"Here,Read/Write head is moving towards left side and reverses its direction afterwards!"<<endl;
    }
    temp=b[0];
    cout<<temp;
    for(SCAN_i=1;SCAN_i<b.size();SCAN_i++){
            if(b[SCAN_i]>=SCAN_m)
            continue;
        cout<<" -> "<<b[SCAN_i];
        // calculating the difference for the read/write head movement
        SCAN_sum+=abs(b[SCAN_i]-temp);
        // head is now at the next I/O request
        temp=a[SCAN_i];
    }
    cout<<"\n";
    cout<<"Total seek time = "<< SCAN_sum<<"\n";
    return 0;
}
       
