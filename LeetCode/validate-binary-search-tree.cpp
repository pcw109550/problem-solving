// 98. Validate Binary Search Tree
#include <algorithm>
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
    bool result;
    public:
        bool isValidBST(TreeNode* root) {
            // O(N)
            result = true;
            check(root);
            return result;
        }
    
        std::pair<int, int> check(TreeNode *node) {
            if (node->left == NULL && node->right == NULL)
                return {node->val, node->val};
            if (node->left == NULL) {
                auto c1 = check(node->right);
                if (c1.first <= node->val)
                    result = false;
                return {std::min(c1.first, node->val), std::max(c1.second, node->val)};     
            }
            if (node->right == NULL) {
                auto c2 = check(node->left);
                if (c2.second >= node->val)
                    result = false;
                return {std::min(c2.first, node->val), std::max(c2.second, node->val)};     
            }
            auto c1 = check(node->right);
            if (c1.first <= node->val)
                result = false;
            auto c2 = check(node->left);
            if (c2.second >= node->val)
                result = false;
            std::pair<int, int> temp = {std::min(c2.first, node->val), std::max(c2.second, node->val)};
            return {std::min(c1.first, temp.first), std::max(c1.second, temp.second)};
        }
};

int main(void) {
    Solution s;
}