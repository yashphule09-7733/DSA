#include <iostream>
#include <string>
using namespace std;
#define MAX 5
class stacks
{
private:
string books[MAX];
int top;
public:
stacks()
{
top = -1;
}
void push(string book)
{
if (top == MAX - 1)
{
cout << "Stack Ovrerflow! NO space for more books." << endl;
return;
}
top++;
books[top] = book;
cout << book << " Book Add Successfully" << endl;
}
void pop()
{
if (top == -1)
{
cout << "Stack UnderFlow! No book to arrange." << endl;
return;
}
cout << books[top] << " Arranged on the shelf." << endl;
top--;
}
void Peek()
{
if (top == -1)
{
cout << "There are no book in shelf" << endl;
return;
}
cout << "Top book;" << books[top] << endl;
}
void display()
{
for (int i = top; i >= 0; i--)
{
cout << books[i] << endl;
}
}
};
int main()
{
string book;
stacks s;
int choice ;
do
{
cout << "\n========Library Stack Menu========" << endl;
cout << "\n1.Return Book " << endl;
cout << "\n2.Arrange Book " << endl;
cout << "\n3.To See Top Book" << endl;
cout << "\n4.Display All The Books" << endl;
cout << "\n5.Exit" << endl;
cout << "Enter your Choice :-";
cin >> choice;
cin.ignore();
switch (choice)
{
case 1:
cout << "Enter book name:-";
getline(cin, book);
s.push(book);
break;
case 2:
s.pop();
break;
case 3:
s.Peek();
break;
case 4:
s.display();
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
