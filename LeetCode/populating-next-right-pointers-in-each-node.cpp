// 116. Populating Next Right Pointers in Each Node
#include <iostream>

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
    public:
        Node* connect(Node* root) {
            // O(N)
            if (root != NULL)
                traversal(root->left, root->right, NULL);
            return root;
        }
    
        void traversal(Node* left, Node* right, Node *next) {
            if (left == NULL && right == NULL)
                return;
            left->next = right;
            right->next = next;
            traversal(left->left, left->right, right->left);
            auto it = right->next == NULL ? NULL : right->next->left;
            traversal(right->left, right->right, it);
        }
};

int main(void) {
    Solution s;
}