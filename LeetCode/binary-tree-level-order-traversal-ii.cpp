// 107. Binary Tree Level Order Traversal II
#include <algorithm>
#include <iostream>
#include <queue>
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
        std::vector<std::vector<int> > levelOrderBottom(TreeNode* root) {
            // O(N)
            std::vector<std::vector<int> > result;
            if (root == NULL)
                return result;
            std::vector<TreeNode *> current;
            current.emplace_back(root);
            while (!current.empty()) {
                std::vector<TreeNode *> next;
                std::vector<int> level;
                for (auto &elem : current) {
                    level.emplace_back(elem->val);
                    if (elem->left != NULL)
                        next.emplace_back(elem->left);
                    if (elem->right != NULL)
                        next.emplace_back(elem->right);
                }
                result.emplace_back(level);
                current = next;
            }
            std::reverse(result.begin(), result.end());
            return result;
        }
};

int main(void) {
    Solution s;
}