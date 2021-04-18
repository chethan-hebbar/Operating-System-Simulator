#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
#include "FIFO.cpp"
#include "SCAN.cpp"
#include "CSCAN.cpp"
#include "LOOK.cpp"
#include "CLOOK.cpp"
int main()
{
   int choice;
   cout<<"DISK SCHEDULING"<<endl;
  do
  {
   cout<<"1.FIFO"<<endl;
   cout<<"2.SCAN"<<endl;
   cout<<"3.CSCAN"<<endl;
   cout<<"4.LOOK"<<endl;
   cout<<"5.CLOOK"<<endl;
   cout<<"Enter your choice of disk scheduling algorithms(enter "0" to exit): ";
   cin>>choice;
   switch(choice)
   {
     case 0:
       break;
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
       cout<<"Please enter a valid choice!"<<endl;
   }
  
  }while(choice!=0);
  
}
