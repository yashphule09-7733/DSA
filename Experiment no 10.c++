//Assignment 8: Create a hash table and handle the collisions using linear probing with or
without replacement
#include<iostream>
using namespace std;
int main(){
int a[10];
for(int i=0; i<10 ; i++)
{
a[i] = -1;
}
int flag = 0;
int n;
start :
cout<<"\n Enter 1 to insert element and 0 to stop inserting"<<endl;
cin>>n;
while(n){
if(flag == 10)
{
cout<<"overloading";
cout<<"\n Resultant hash table is :"<<endl;
for(int i=0; i<10 ; i++)
{
cout<<"\t"<<a[i]<<endl;
}
return 0;
}
int k;
cout<<"\n Enter Element =>";
cin>>k;
int temp = k%10;
middle :
if(a[temp]== -1)
{
a[temp] = k;
flag++;
goto start;
}
else
{
while(a[temp] != -1 && flag != 10)
{
if(temp == 9)
{
temp = 0;
}
else
temp++;
goto middle;
}
}
}
cout<<"\n Resultant hash table is :"<<endl;
for(int i=0; i<10 ; i++)
{
cout<<"\t"<<i<<". "<<a[i]<<endl;
}
}
