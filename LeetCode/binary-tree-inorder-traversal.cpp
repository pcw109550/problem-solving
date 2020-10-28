// 94. Binary Tree Inorder Traversal
#include <iostream>
#include <stack>
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
    public:
        std::vector<int> inorderTraversal(TreeNode* root) {
            // O(N)
            std::vector<int> result;
            std::stack<TreeNode *> S;
            auto cur = root;
            while (cur != NULL || !S.empty()) {
                while (cur != NULL) {
                    S.push(cur);
                    cur = cur->left;
                }
                cur = S.top(); S.pop();
                result.emplace_back(cur->val);
                cur = cur->right;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}