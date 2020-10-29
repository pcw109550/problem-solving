// 101. Symmetric Tree
#include <iostream>
#include <stack>

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
        bool isSymmetric(TreeNode* root) {
            // O(N)
            if (root == NULL)
                return true;
            std::stack<TreeNode *> L, R;
            L.push(root); R.push(root);
            while (!L.empty() && !R.empty()) {
                auto curr_l = L.top(); L.pop();
                auto curr_r = R.top(); R.pop();
                if (curr_l == NULL || curr_r == NULL) {
                    if (curr_l != curr_r)
                        return false;
                    continue;
                }
                if (curr_l->val != curr_r->val)
                    return false;
                L.push(curr_l->left); L.push(curr_l->right);
                R.push(curr_r->right); R.push(curr_r->left);
            }
            if (!L.empty() || !R.empty())
                return false;
            return true;
        }
};

int main(void) {
    Solution s;
}