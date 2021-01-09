// 337. House Robber III
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
    public:
        int rob(TreeNode* root) {
            // O(N)
            auto result = dfs(root);
            return std::max(result.first, result.second);
        }
    
        std::pair<int, int> dfs(TreeNode *node) {
            if (node == NULL)
                return {0, 0};
            auto left_res = dfs(node->left);
            auto right_res = dfs(node->right);
            std::pair<int, int> current;
            current.first = node->val + left_res.second + right_res.second;
            current.second = std::max(left_res.first, left_res.second);
            current.second += std::max(right_res.first, right_res.second);
            return current;
        }
        
};

int main(void) {
    Solution s;
}