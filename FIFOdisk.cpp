#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,n,m,sum=0,x,y,h;
    cout<<"Enter total number of tracks on the disk: ";
    cin>>m;
    cout<<"Enter total number of requests: ";
    cin>>n;
    cout<<"Please enter the requests\n";
    int tmp[n];
    //a vector of size n
    vector <int> a(n);
    vector<int>::iterator it;
    for(i=0;i<n;i++){
        cout<<"Enter the request "<<i+1<<": ";
        cin>>a[i];
        if(a[i]>=m)
        {
             cout<<"Error! Unknown position of track "<<a[i]<<" on the disk \n";
             a.erase(a.begin()+i);
        }
    }
    cout<<"Enter the head position: ";
    cin>>h;
    // head position is at h in the beginning
    int temp=h;
    cout<<temp;
    for(i=0;i<n;i++){
            if(a[i]==0)
            continue;
        cout<<" -> "<<a[i]<<' ';
        // calculating the difference for the head movement
        sum+=abs(a[i]-temp);
        // head is now at the next I/O request
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    return 0;
}
