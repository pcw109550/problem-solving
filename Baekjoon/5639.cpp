#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int key;
    Node *left;
    Node *right;
} Node;

Node root;

void insert(Node *current, int key) {
    if (current->key > key) {
        if (current->left) { insert(current->left, key);  }
        else {
            current->left = (Node *)malloc(sizeof(Node));
            current->left->key = key;
        }
    } else { 
        if (current->right) { insert(current->right, key); }
        else {
            current->right = (Node *)malloc(sizeof(Node));
            current->right->key = key;
        }
    }
}

void postorder(Node *current) {
    if (current->left)  { postorder(current->left);  }
    if (current->right) { postorder(current->right); }
    cout << current->key << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int key; cin >> key; root.key = key;
    while (cin >> key) {
        insert(&root, key);
    }
    postorder(&root);
}