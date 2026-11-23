 
#include <iostream>
using namespace std;
struct Node
{
int data;
Node *next;
};
class linkedlist
{
private:
Node *head;
 
public:
linkedlist()
{
head = NULL;
}
void createlist(){
int n, value;
cout << "\nEnter number of Nodes: ";
cin >> n;
if (n <= 0)
{
cout << "List is Empty";
return;
}
for (int i = 1; i <= n; i++)
{
cout << "\nEnter value" << i << ":";
cin >> value;
insertEnd(value);
}
cout << "Linklist is created" << endl;
}
 
void insertEnd(int value){
Node *newNode = new Node;
newNode->data = value;
newNode->next = NULL;
 
if (head == NULL)
{
head = newNode;
return;
}
Node *temp = head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = newNode;
}
void display(){
if (head == NULL)
{
cout << "\nLinkedlist is Empty.\n";
return;
}
Node *temp = head;
cout << "\nLinklist:";
while (temp != NULL)
{
cout << temp->data << "->";
temp = temp->next;
}
}
void deleteNode(){
if(head==NULL)
{
cout<<"\nList is Empty.\n";
return;
}
int value;
cout<<"\nEnter value to delete: ";
cin>>value;
Node *temp=head;
Node *previous=NULL;
 
if(head->data==value)
{
head=head->next;
delete temp;
 
cout<<"\nNode Deleted.\n";
return;
}
 
while(temp!=NULL && temp->data!=value)
{
previous=temp;
temp=temp->next;
}
 
if(temp==NULL)
{
cout<<"\nValue Not Found.\n";
return;
}
 
previous->next=temp->next;
delete temp;
 
cout<<"\nNode Deleted Successfully.\n";
}
};
int main()
{
linkedlist L;
int choice = 0;
do
{
cout << "\n========LinkedList Menu========" << endl;
cout << "1.Create LinkedList" << endl;
cout << "2.Insert element at end" << endl;
cout << "3.Delete Node" << endl;
cout << "4.Display Linkedlist" << endl;
cout << "5.Exit" << endl;
cout << "Enter your Choice :-";
cin >> choice;
cin.ignore();
switch (choice)
{
case 1:
L.createlist();
break;
case 2:
int value;
cout << "Enter value";
cin>>value;
L.insertEnd(value);
break;
case 3:
L.deleteNode();
break;
case 4:
L.display();
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
