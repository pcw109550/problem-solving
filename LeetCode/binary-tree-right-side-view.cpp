// 199. Binary Tree Right Side View
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
        std::vector<int> rightSideView(TreeNode* root) {
            // O(N)
            std::vector<int> result;
            if (root == NULL)
                return result;
            std::vector<TreeNode *> cur, next;
            cur.push_back(root);
            while (!cur.empty()) {
                result.push_back(cur.back()->val);
                for (auto it : cur) {
                    if (it->left != NULL)
                        next.push_back(it->left);
                    if (it->right != NULL)
                        next.push_back(it->right);
                }
                cur = next;
                next.clear();
            }
            return result;
        }
};

int main(void) {
    Solution s;
}