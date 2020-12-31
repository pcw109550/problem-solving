// 897. Increasing Order Search Tree

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode *current;
        TreeNode *increasingBST(TreeNode *root) {
            // O(N)
            TreeNode temp;
            current = &temp;
            inorder_traversal(root);
            return temp.right;
        }

        void inorder_traversal(TreeNode *node) {
            if (node->left != NULL)
                inorder_traversal(node->left);
            current->right = new TreeNode(node->val);
            current = current->right;
            if (node->right != NULL)
                inorder_traversal(node->right);
        }
};

int main(void) {
    Solution s;
}