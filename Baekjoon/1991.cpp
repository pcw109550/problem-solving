#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    char current, left, right;
} Node;

Node tree[26];

void preorder(char current) {
    int num = current - 'A';
    cout << tree[num].current;
    if (tree[num].left  != '.') preorder(tree[num].left);
    if (tree[num].right != '.') preorder(tree[num].right);
}

void inorder(char current) {
    int num = current - 'A';
    if (tree[num].left  != '.') inorder(tree[num].left);
    cout << tree[num].current;
    if (tree[num].right != '.') inorder(tree[num].right);
}

void postorder(char current) {
    int num = current - 'A';
    if (tree[num].left  != '.') postorder(tree[num].left);
    if (tree[num].right != '.') postorder(tree[num].right);
    cout << tree[num].current;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; char current, left, right;
    for (int i = 0; i < N; i++) {
        cin >> current >> left >> right;
        tree[current - 'A'].current = current;
        tree[current - 'A'].left = left;
        tree[current - 'A'].right = right;   
    }
    preorder('A');  cout << '\n';
    inorder('A');   cout << '\n';
    postorder('A'); cout << '\n';
}