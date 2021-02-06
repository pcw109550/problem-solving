// 117. Populating Next Right Pointers in Each Node II
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
            // O(N ** 2)
            if (root == NULL)
                return NULL;
            int level = 1;
            while (traversal(root->left, root->right, root, level)) 
                level++;
            return root;
        }
    
        bool traversal(Node* left, Node* right, Node *parent, int level) {
            if (level == 1) {
                if (left != NULL)
                    left->next = right == NULL ? get_next(parent) : right;
                if (right != NULL)
                    right->next = get_next(parent);
                return true;
            }
            bool l = left == NULL ? false : traversal(left->left, left->right, left, level - 1);
            bool r = right == NULL ? false : traversal(right->left, right->right, right, level - 1);
            return l || r;
        }
    
        Node* get_next(Node* node) {
            if (node == NULL)
                return NULL;
            node = node->next;
            while (node != NULL) {
                if (node->left)
                    return node->left;
                if (node->right)
                    return node->right;
                node = node->next;
            }
            return NULL;
        }
};

int main(void) {
    Solution s;
}