// 637. Average of Levels in Binary Tree
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
    public:
        std::vector<double> averageOfLevels(TreeNode* root) {
            std::vector<double> result;
            std::vector<TreeNode *> cur;
            cur.push_back(root);
            while (!cur.empty()) {
                std::vector<TreeNode *> next;
                long long acc = 0;
                for (auto it : cur) {
                    acc += it->val;
                    if (it->left)
                        next.push_back(it->left);
                    if (it->right)
                        next.push_back(it->right);
                }
                result.push_back(static_cast<double>(acc) / cur.size());
                cur = next;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}