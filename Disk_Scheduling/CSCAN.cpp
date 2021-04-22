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
int CSCAN(){
    int CSCAN_i,CSCAN_k,CSCAN_n,CSCAN_m,CSCAN_sum=0,CSCAN_h;
    cout<<"Enter total number of tracks on the disk: ";
    cin>>CSCAN_m;
    cout<<"Enter total number of requests: ";
    cin>>CSCAN_n;
    cout<<"Please enter the requests!"<<endl;
    vector <int> a(CSCAN_n),b;
    for(CSCAN_i=0;CSCAN_i<CSCAN_n;CSCAN_i++){
        cout<<"Enter the request "<<CSCAN_i+1<<": ";
        cin>>a[CSCAN_i];
        if(a[CSCAN_i]>=CSCAN_m)
        {
             cout<<"Error! Unknown position of track "<<a[CSCAN_i]<<" on the disk \n";
        }

    }
    cout<<"Enter read/write head position: ";
    cin>>CSCAN_h;
    int temp=CSCAN_h;
    a.push_back(CSCAN_h);
    a.push_back(CSCAN_m-1);
    a.push_back(0);
    sort(a.begin(),a.end());
    for(CSCAN_i=0;CSCAN_i<a.size();CSCAN_i++){
        if(CSCAN_h==a[CSCAN_i])
            break;
    }
    CSCAN_k=CSCAN_i;
    if(CSCAN_k<CSCAN_n/2){
        for(CSCAN_i=CSCAN_k;CSCAN_i<a.size();CSCAN_i++){
            b.push_back(a[CSCAN_i]);
        }
        for(CSCAN_i=0;CSCAN_i<=CSCAN_k-1;CSCAN_i++){
            b.push_back(a[CSCAN_i]);
        }
        //"Here,Read/Write head is moving towards right side(services requests on its way) , reaches "0"  and goes to the extreme position
        // then reverses its direction(services requests on its way).
         cout<<"Here,Read/Write head is moving towards right side and reverses its direction afterwards!"<<endl;
    }
    else{
        for(CSCAN_i=CSCAN_k;CSCAN_i>=0;CSCAN_i--){
            b.push_back(a[CSCAN_i]);
        }
        for(CSCAN_i=a.size()-1;CSCAN_i>=CSCAN_k+1;CSCAN_i--){
            b.push_back(a[CSCAN_i]);
        }
        //"Here,Read/Write head is moving towards left side(services requests on its way) , reaches "0"  and goes to the extreme position
        // then reverses its direction(services requests on its way).
        cout<<"Here,Read/Write head is moving towards left side and reverses its direction afterwards!"<<endl;
    }
    temp=b[0];   //head h is at the beginning of vector b
    cout<<temp;
    for(CSCAN_i=1;CSCAN_i<b.size();CSCAN_i++){
            if(b[CSCAN_i]>=CSCAN_m)
            continue;
        cout<<" -> "<<b[CSCAN_i];
        // calculating the difference for the read/write head movement
        CSCAN_sum+=abs(b[CSCAN_i]-temp);
        // head is now at the next I/O request
        temp=b[CSCAN_i];
    }
    cout<<"\n";
    cout<<"Total seek time =  "<< CSCAN_sum<<"\n";
    return 0;
}
           
