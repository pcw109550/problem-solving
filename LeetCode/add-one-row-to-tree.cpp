// 623. Add One Row to Tree
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
        TreeNode* addOneRow(TreeNode* root, int v, int d) {
            // O(N)
            int height = 1;
            TreeNode *result;
            if (d == 1)
                return new TreeNode(v, root, NULL);
            std::vector<TreeNode *> cur, next;
            cur.push_back(root);
            while (cur.size()) {
                height++;
                if (height == d) {
                    for (auto it : cur) {
                        it->left = new TreeNode(v, it->left, NULL);
                        it->right = new TreeNode(v, NULL, it->right);
                    }
                    break;
                }
                for (auto it : cur) {
                    if (it->left)
                        next.push_back(it->left);
                    if (it->right)
                        next.push_back(it->right);
                }
                cur = next;
                next.clear();
            }
            return root;
    }
};

int main(void) {
    Solution s;
}