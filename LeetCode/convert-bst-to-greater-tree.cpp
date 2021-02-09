// 538. Convert BST to Greater Tree
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
    int sum;
    public:
        TreeNode* bstToGst(TreeNode* root) {
            // O(N)
            if (root != NULL)
                traversal(root);
            return root;
        }
    
        void traversal(TreeNode* root) {
            if (root->right != NULL)
                traversal(root->right);
            sum += root->val;
            root->val = sum;
            if (root->left != NULL)
                traversal(root->left);
        }
};

int main(void) {
    Solution s;
}