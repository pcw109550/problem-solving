// 114. Flatten Binary Tree to Linked List
#include <iostream>
#include <utility>

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
        void flatten(TreeNode* root) {
            // Time O(N)
            if (root == NULL)
                return;
            traversal(root);
        }
    
        std::pair<TreeNode *, TreeNode *> traversal(TreeNode *node) {
            auto left = node->left; node->left = NULL;
            auto right = node->right; node->right = NULL;
            std::pair<TreeNode *, TreeNode *> l = {NULL, NULL}, r = {NULL, NULL};
            if (left) {
                l = traversal(left);
                node->right = l.first;
            }
            if (right) {
                r = traversal(right);
                if (l.first == NULL && l.second == NULL) {
                    node->right = r.first;
                    return {node, r.second};
                } else {
                    l.second->right = r.first;
                    return {node, r.second};
                }
            } else if (l.first != NULL && l.second != NULL) {
                return {node, l.second};
            }
            return {node, node};
        }
    
        
};

int main(void) {
    Solution s;
}