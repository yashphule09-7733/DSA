#include &lt;iostream&gt;
using namespace std;

class Graph {
private:
int vertices, adj[20][20];

public:
Graph() {
vertices = 0;

for (int i = 0; i &lt; 20; i++) {
for (int j = 0; j &lt; 20; j++) {
adj[i][j] = 0;
}
}
}
void createGeaph() {
int edges, source, destination;
cout &lt;&lt; &quot;\nEnter number of vertices:&quot;;

cin &gt;&gt; vertices;
for (int i = 0; i &lt; vertices; i++) {
for (int j = 0; j &lt; vertices; j++) {
adj[i][j] = 0;
}
}
cout &lt;&lt; &quot;Enter number od edges: &quot;;
cin &gt;&gt; edges;

cout &lt;&lt; &quot;\nEnter edges (source destination);\n&quot;;
for (int i = 0; i &lt; edges; i++) {

cout &lt;&lt; &quot;Edge&quot; &lt;&lt; i + 1 &lt;&lt; &quot;:&quot;;
cin &gt;&gt; source &gt;&gt; destination;

if (source &gt;= 0 &amp;&amp; source &lt; vertices &amp;&amp; destination &gt;= 0 &amp;&amp;
destination &lt; vertices) {
adj[source][destination] = 1;
adj[destination][source] = 1;
} else {
cout &lt;&lt; &quot;\nInvalid vertex number. \n&quot;;
i--;
}
}
cout &lt;&lt; &quot;\nGraph created successfully.\n&quot;;
}
void displayMatrix() {
if (vertices == 0) {
cout &lt;&lt; &quot;\nGraph is not created.\n&quot;;

return;
}
cout &lt;&lt; &quot;\nAdjacency Matrix: \n\n&quot;;
for (int i = 0; i &lt; vertices; i++) {
cout &lt;&lt; i &lt;&lt; &quot; &quot;;
}
cout &lt;&lt; endl;
// Display matrix
for (int i = 0; i &lt; vertices; i++) {
cout &lt;&lt; i &lt;&lt; &quot;: &quot;;
for (int j = 0; j &lt; vertices; j++) {
cout &lt;&lt; adj[i][j] &lt;&lt; &quot; &quot;;
}
cout &lt;&lt; endl;
}
}
void DFS(int startVertex) {
if (vertices == 0) {
cout &lt;&lt; &quot;\nGraph is not created.\n&quot;;
return;
}
if (startVertex &lt; 0 || startVertex &gt;= vertices) {
cout &lt;&lt; &quot;\nInvalid starting vertex.\n&quot;;
return;
}
int visited[20];
int stack[20];
int top = -1;

for (int i = 0; i &lt; vertices; i++) {
visited[i] = 0;
}
top++;
stack[top] = startVertex;
cout &lt;&lt; &quot;\nDFS traversal:&quot;;
while (top != -1) {
int current = stack[top];
top--;
if (visited[current] == 0) {
cout &lt;&lt; current &lt;&lt; &quot; &quot;;

visited[current] = 1;
for (int i = vertices - 1; i &gt;= 0; i--) {
if (adj[current][i] == 1 &amp;&amp; visited[i] == 0) {
top++;
stack[top] = i;
}
}
}
}
}
};
int main() {
Graph g;
int choice;
do {
cout &lt;&lt; &quot;\n======== Graph Menu ========&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;1. Create Graph&quot; &lt;&lt; endl;

cout &lt;&lt; &quot;2. Display Adjacency Matrix&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;3. DFS Traversal&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;4. Exit&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;Enter your Choice :- &quot;;
cin &gt;&gt; choice;
cin.ignore();
switch (choice) {
case 1:
g.createGeaph();
break;
case 2:
g.displayMatrix();
break;
case 3: {
int startVertex;
cout &lt;&lt; &quot;Enter starting vertex: &quot;;
cin &gt;&gt; startVertex;
g.DFS(startVertex);
break;
}
case 4:
cout &lt;&lt; &quot;exit&quot; &lt;&lt; endl;
break;
default:
cout &lt;&lt; &quot;Invalid Input&quot; &lt;&lt; endl;
break;
}
} while (choice != 4);
return 0;

}
