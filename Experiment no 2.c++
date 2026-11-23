using namespace std;
class Queue{
private:
int queue[5];
int front;
int rear;
int size;
public:
Queue(){
size=5;
front=-1;
rear=-1;
}
void insert(int value){
if (rear==size-1){
cout<<"Queue Is Full"<<endl;
return;
}
if(front==-1){
front=0;
}
rear++;
queue[rear]=value;
cout<<"Element Inserted"<<endl;
}
void display(){
if(front==-1){
cout<<"Queue Is Empty"<<endl;
return;
}
for(int i=front;i<=rear;i++){
cout<<queue[i]<<" ";
}
}
void peek(){
if(front==-1){
cout<<"Queue Is Empty"<<endl;
return;
}
cout<<"\nFirst value "<<queue[front];
}
void dequeue(){
if(front==-1){
cout<<"Queue Is Empty"<<endl;
front=rear=-1;
return;
}
cout<<"Deleted Element:"<<queue[front];
front++;
if (front>rear){
front=rear=-1;
}
}
};
int main(){
int Value;
Queue a;
int choice ;
do
{
cout << "\n========Queue Menu========" << endl;
cout << "\n1.Insurt " << endl;
cout << "\n2.Delete" << endl;
cout << "\n3.Peek" << endl;
cout << "\n4.Display "<< endl;
cout << "\n5.Exit" << endl;
cout << "Enter your Choice :-";
cin >> choice;
cin.ignore();
switch (choice)
{
case 1:
cout << "Enter book name:-";
cin>>Value;
a.insert(Value);
break;
case 2:
a.dequeue();
break;
case 3:
a.peek();
break;
case 4:
a.display();
break;
case 5:
cout << "exit" << endl;
break;
default:
cout << "Invalid Input" << endl;
break;
}
} while (choice != 5);
return 0;
