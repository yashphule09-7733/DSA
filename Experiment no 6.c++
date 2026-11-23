#include &lt;iostream&gt;
#include &lt;stack&gt;
using namespace std;

class Node
{
public:
int data;
Node *left;
Node *right;
Node(int value)
{
data = value;
left = NULL;
right = NULL;
}
};

class BST
{
private:
Node *root;
Node *insert(Node *root, int value)

{
if (root == NULL)
{
return new Node(value);
}
if (value &lt; root-&gt;data)
{
root-&gt;left = insert(root-&gt;left, value);
}
else if (value &gt; root-&gt;data)
{
root-&gt;right = insert(root-&gt;right, value);
}
else
{
cout &lt;&lt; &quot;\nDuplicate value not inserted.\n&quot;;
}
return root;
}

public:
BST()
{
root = NULL;
}
void createBST()
{
int n, value;
cout &lt;&lt; &quot;\nEnter number of nodes:&quot;;

cin &gt;&gt; n;
cout &lt;&lt; &quot;\nEnter node value:&quot;;
for (int i = 1; i &lt;= n; i++)
{
cin &gt;&gt; value;
root = insert(root, value);
}
}
int Hight(Node *root)
{
if (root == NULL)
return 0;

int leftHight = Hight(root-&gt;left);
int rightHight = Hight(root-&gt;right);

if (leftHight &gt; rightHight)
return leftHight + 1;
else
return rightHight + 1;
}
void DisplayHight()
{
cout &lt;&lt; &quot;hight of tree: &quot; &lt;&lt; Hight(root) &lt;&lt; endl;
}
void leaves(Node *root)
{
if (root == NULL)
return;

if (root-&gt;left == NULL &amp;&amp; root-&gt;right == NULL)
{
cout &lt;&lt; root-&gt;data &lt;&lt; &quot;, &quot;;
return;
}
leaves(root-&gt;left);
leaves(root-&gt;right);
}
void displayleaves(){
leaves(root);
}
void displayLevelWise(){
if(root==NULL){
cout&lt;&lt;&quot;\nTree is empty.\n&quot;;
return;
}
Node*queue[100];
int front = 0;
int rear = 0;
queue[rear] = root;
rear++;
cout&lt;&lt;&quot;\nLevel-Wise BST:\n&quot;;
while(front&lt;rear){
int nodesAtLevel = rear - front;
cout &lt;&lt; &quot;Level: &quot;;
for (int i = 0; i &lt; nodesAtLevel; i++)
{
Node *current = queue[front];

front++;
cout &lt;&lt; current-&gt;data &lt;&lt; &quot; &quot;;
if (current-&gt;left != NULL)
{
queue[rear] = current-&gt;left;
rear++;
}
if (current-&gt;right != NULL)
{
queue[rear] = current-&gt;right;
rear++;
}
}
}
}
Node* copyTree(Node* root){
if(root==NULL){
return NULL;
}
Node* newNode = new Node(root-&gt;data);
newNode-&gt;left = copyTree(root-&gt;left);
newNode-&gt;right = copyTree(root-&gt;right);
return newNode;

}
BST* copyNewTree(){
BST* newTree =new BST();
newTree-&gt;root = copyTree(root);
return newTree;

}
};

int main()
{
BST Tree;
int choice;
BST *newTree = NULL;
if (newTree != NULL){
delete newTree;
newTree = NULL;
}
newTree = Tree.copyNewTree();

do
{
cout &lt;&lt; &quot;\n========BST Tree========&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;1.Create Tree&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;2.display Hight&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;3.display leaves&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;4.display Level Wise &quot; &lt;&lt; endl;
cout &lt;&lt; &quot;5.Copy display Hight&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;6.Copy display leaves&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;7.Copy display Level Wise &quot; &lt;&lt; endl;
cout &lt;&lt; &quot;8.Exit&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;Enter your Choice :-&quot;;
cin &gt;&gt; choice;
cin.ignore();
switch (choice)

{
case 1:
Tree.createBST();
break;
case 2:
Tree.DisplayHight();
break;
case 3:
Tree.displayleaves();
break;
case 4:
Tree.displayLevelWise();
break;
case 5:
newTree-&gt;DisplayHight();
break;
case 6:
newTree-&gt;displayLevelWise();
break;
case 7:
newTree-&gt;displayleaves();
break;
case 8:
cout &lt;&lt; &quot;exit&quot; &lt;&lt; endl;
break;
default:
cout &lt;&lt; &quot;Invalid Input&quot; &lt;&lt; endl;
break;
}

} while (choice != 8);
return 0;

}
