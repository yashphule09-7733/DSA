#include <iostream> using namespace std; struct Node{ int data; Node *left;
Node *right;
};
class Binary_Tree{ private :
Node *root;
public:
Binary_Tree(){ root = NULL;
}
Node*create(){ int value; cout<<"\nEnter node value (-1 for No Node):"; cin>> value; if(value == -1) return NULL;
Node *newNode = new Node; newNode->data = value; cout << "Enter Left Child of"; newNode->left = create(); cout<< "Enter Right Child of"; newNode->right = create(); return newNode;
} void build(){ cout<<"\nCreate Binary Tree\n"; root = create();
}
void inorder(Node *temp){ if(temp == NULL) return; inorder(temp->left); cout<<temp->data<<""; inorder(temp->right);
}
void preoder(Node *temp){


if(temp == NULL) return;
preoder(temp->left); cout<<temp->data<<""; preoder(temp->right);
}
void postorder(Node *temp){ if(temp == NULL) return; postorder(temp->left); cout<<temp->data<<""; postorder(temp->right);
}
void display_inorder(){ cout <<"\nInorder Traversal :"; inorder(root);
}
void display_preorder(){ cout <<"\nPostorder Traversal :"; postorder(root);
}
void display_postorder(){ cout <<"\nPreorder Traversal :"; postorder(root);
} };
int main(){
Binary_Tree Tree; int choice;
do
{
cout << "\n========Binary Tree========" << endl; cout << "1.Create Tree" << endl; cout << "2.display inorder" << endl; cout << "3.display postorder" << endl; cout << "4.display preorder " << endl; cout << "5.Exit" << endl; cout << "Enter your Choice :-"; cin >> choice; cin.ignore(); switch (choice)
{
case 1:
Tree.build(); 


break; case 2:
Tree.display_inorder(); break; case 3:
Tree.display_postorder(); break; case 4:
Tree.display_preorder(); break; case 5: cout << "exit" << endl; break; default: cout << "Invalid Input" << endl; break;
}
} while (choice != 5); return 0;
}

