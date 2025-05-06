#include <iostream>
#include <queue>
#include <stack>
#include <omp.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* insert(Node* root, int val);
    void bfs(Node* root);
    void dfs(Node* root);
    void deleteTree(Node* root);
};

// Level-order insertion
Node* Tree::insert(Node* root, int val) {
    if (!root)
        return new Node(val);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (!cur->left) {
            cur->left = new Node(val);
            return root;
        } else {
            q.push(cur->left);
        }

        if (!cur->right) {
            cur->right = new Node(val);
            return root;
        } else {
            q.push(cur->right);
        }
    }
    return root;
}

// Parallel BFS using OpenMP
void Tree::bfs(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    cout << "\nParallel BFS Traversal:\n";
    while (!q.empty()) {
        int levelSize = q.size();

        #pragma omp parallel for
        for (int i = 0; i < levelSize; ++i) {
            Node* node;
            #pragma omp critical
            {
                node = q.front();
                q.pop();
                cout << node->data << " ";
            }

            #pragma omp critical
            {
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        cout << endl;
    }
}

// Parallel DFS using OpenMP (preorder)
void Tree::dfs(Node* root) {
    if (!root) return;

    stack<Node*> s;
    s.push(root);

    cout << "\nParallel DFS (Preorder) Traversal:\n";
    while (!s.empty()) {
        Node* node = s.top();
        s.pop();

        cout << node->data << " ";

        // Parallel region to push children (not truly concurrent stack-safe)
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                if (node->right) {
                    #pragma omp critical
                    s.push(node->right);
                }
            }
            #pragma omp section
            {
                if (node->left) {
                    #pragma omp critical
                    s.push(node->left);
                }
            }
        }
    }
}

// Post-order delete
void Tree::deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Tree t;
    Node* root = nullptr;
    int val;
    char choice;

    cout << "Enter values to create a binary tree:\n";
    do {
        cout << "Enter value: ";
        cin >> val;
        root = t.insert(root, val);
        cout << "Insert another? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Run BFS and DFS
    t.bfs(root);
    t.dfs(root);

    // Free memory
    t.deleteTree(root);
    return 0;
}
