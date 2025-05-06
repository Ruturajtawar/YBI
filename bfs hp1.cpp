#include <iostream> 
#include <stdlib.h> 
#include <queue> 
#include <omp.h> // For OpenMP (if you decide to use parallelism later) 
using namespace std; 
class node { 
public: 
node *left, *right; 
int data; 
}; 
class Breadthfs { 
public: 
node* insert(node*, int); 
void bfs(node*); 
void deleteTree(node*); 
}; 
// Insert a node into the binary tree 
node* insert(node* root, int data) { 
if (!root) { 
root = new node; 
root->left = NULL; 
root->right = NULL; 
root->data = data; 
return root; 
} 
queue<node*> q; 
q.push(root); 
while (!q.empty()) { 
node* temp = q.front(); 
q.pop(); 
if (temp->left == NULL) { 
temp->left = new node; 
temp->left->left = NULL; 
temp->left->right = NULL; 
temp->left->data = data; 
return root; 
} else { 
q.push(temp->left); 
} 
if (temp->right == NULL) { 
temp->right = new node; 
temp->right->left = NULL; 
temp->right->right = NULL; 
temp->right->data = data; 
return root; 
} else { 
q.push(temp->right); 
} 
} 
// Always return root if no other conditions are met 
return root; 
} 
// Breadth-First Search using a queue 
void bfs(node* head) { 
if (head == NULL) return; 
queue<node*> q; 
q.push(head); 
while (!q.empty()) { 
int qSize = q.size(); 
// Process nodes level by level 
for (int i = 0; i < qSize; i++) { 
node* currNode = q.front(); 
q.pop(); 
cout << currNode->data << " "; 
// Enqueue children nodes in order 
if (currNode->left) q.push(currNode->left); 
if (currNode->right) q.push(currNode->right); 
} 
cout << endl; // New line after each level for better readability 
} 
} 
// Function to delete the entire tree and free memory 
void deleteTree(node* root) { 
if (root == NULL) return; 
// Post-order traversal to delete nodes 
deleteTree(root->left); 
deleteTree(root->right); 
delete root; // Delete current node 
} 
int main() { 
node* root = NULL; 
int data; 
char ans; 
// Insert nodes into the binary tree 
do { 
cout << "\nEnter data: "; 
cin >> data; 
root = insert(root, data); 
cout << "Do you want to insert one more node (y/n)? "; 
cin >> ans; 
} while (ans == 'y' || ans == 'Y'); 
// Perform BFS traversal 
cout << "BFS Traversal Output: \n"; 
bfs(root); 
// Clean up memory by deleting the tree 
deleteTree(root); 
return 0; 
}
