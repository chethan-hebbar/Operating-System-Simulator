//SCAN DISK SCHEDULING
#include<bits/stdc++.h>
using namespace std;
int SCAN(){
    int i,k,n,m,sum=0,h;
    cout<<"Enter total number of tracks on the disk: ";
    cin>>m;
    cout<<"Enter total number of requests: ";
    cin>>n;
    cout<<"Please enter the requests!"<<endl;
    int tmp[n];
    vector <int> a(n),b;
    for(i=0;i<n;i++){
        cout<<"Enter the request "<<i+1<<": ";
        cin>>a[i];
        if(a[i]>=m)
        {
             cout<<"Error! Unknown position of track "<<a[i]<<" on the disk \n";
        }
    }
    cout<<"Enter read/write head position: ";
    cin>>h;
    int temp=h;
    a.push_back(h);
    a.push_back(m-1);
    a.push_back(0);
  sort(a.begin(),a.end());
    cout<<"\n";
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            b.push_back(a[i]);
        }
        cout<<"Here,Read/Write head is moving towards right side and reverses its direction afterwards!"<<endl;
    }
    else{
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            b.push_back(a[i]);
        }
        cout<<"Here,Read/Write head is moving towards left side and reverses its direction afterwards!"<<endl;
    }
    temp=b[0];
    cout<<temp;
    for(i=1;i<b.size();i++){
            if(b[i]>=m)
            continue;
        cout<<" -> "<<b[i];
        // calculating the difference for the read/write head movement
        sum+=abs(b[i]-temp);
        // head is now at the next I/O request
        temp=a[i];
    }
    cout<<"\n";
    cout<<"Total seek time = "<< sum<<"\n";
    return 0;
}
