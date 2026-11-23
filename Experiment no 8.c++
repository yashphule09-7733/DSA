#include <iostream>
using namespace std;
class Graph {
private:
int vertices, adj[20][20];
public:
Graph() {
vertices = 0;

for (int i = 0; i < 20; i++) {
for (int j = 0; j < 20; j++) {
adj[i][j] = 0;
}
}
}
void createGeaph() {
int edges, source, destination;
cout << "\nEnter number of vertices:";
cin >> vertices;

if (vertices <= 0 || vertices > 20) {
cout << "\nNumber of vertices must be between 1 and
20.\n";
vertices = 0;
return;
}
for (int i = 0; i < vertices; i++) {
for (int j = 0; j < vertices; j++) {
adj[i][j] = 0;
}
}
cout << "Enter number od edges: ";
cin >> edges;
cout << "\nEnter edges (source destination);\n";
for (int i = 0; i < edges; i++) {
cout << "Edge" << i + 1 << ":";
cin >> source >> destination;

if (source >= 0 && source < vertices && destination >= 0 &&
destination < vertices) {
adj[source][destination] = 1;
adj[destination][source] = 1;
} else {
cout << "\nInvalid vertex number. \n";
i--;
}
}
cout << "\nGraph created successfully.\n";
}
void displayMatrix() {
if (vertices == 0) {

cout << "\nGraph is not created.\n";
return;
}
cout << "\nAdjacency Matrix: \n\n";
for (int i = 0; i < vertices; i++) {
cout << i << " ";
}
cout << endl;
// Display matrix
for (int i = 0; i < vertices; i++) {
cout << i << ": ";
for (int j = 0; j < vertices; j++) {
cout << adj[i][j] << " ";
}
cout << endl;
}
}
void BFS(int root) {
if (vertices == 0) {
cout << "\nGraph is not created.\n";
return;
}
if (root < 0 || root >= vertices) {
cout << "\nInvalid starting vertex.\n";
return;
}

int queue[20];
bool visited[20] = {};
int front = 0;
int rear = 0;
queue[rear++] = root;
visited[root] = true;

cout << "\nBFS Traversal: ";
while (front < rear) {
int current = queue[front++];
cout << current << " ";

for (int neighbor = 0; neighbor < vertices; neighbor++) {
if (adj[current][neighbor] && !visited[neighbor]) {
visited[neighbor] = true;
queue[rear++] = neighbor;
}
}
}
cout << endl;
}
};
int main() {
Graph g;
int choice;
do {
cout << "\n======== Graph Menu ========" << endl;
cout << "1. Create Graph" << endl;
cout << "2. Display Adjacency Matrix" << endl;
cout << "3. BFS Traversal" << endl;
cout << "4. Exit" << endl;
cout << "Enter your Choice :- ";
cin >> choice;
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
cout << "Enter starting vertex: ";
cin >> startVertex;
g.BFS(startVertex);
break;
}
case 4:
cout << "exit" << endl;
break;
default:
cout << "Invalid Input" << endl;
break;
}
} while (choice != 4);
return 0;
}}
