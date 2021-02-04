// 669. Trim a Binary Search Tree
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int _low, _high;
    public:
        TreeNode* trimBST(TreeNode* root, int low, int high) {
            // O(N)
            _low = low;
            _high = high;
            return traversal(root);
        }
    
        TreeNode* traversal(TreeNode *node) {
            if (node == NULL)
                return NULL;
            if (node->val < _low)
                return traversal(node->right);
            if (node->val > _high)
                return traversal(node->left);
            if (node->left != NULL)
                node->left = traversal(node->left);
            if (node->right != NULL)
                node->right = traversal(node->right);
            return node;
        }
};

int main(void) {
    Solution s;
}