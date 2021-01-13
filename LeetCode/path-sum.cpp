// 112. Path Sum
#include <iostream>
#include <queue>
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
        bool hasPathSum(TreeNode* root, int sum) {
            // O(N)
            if (root == NULL)
                return false;
            std::queue<std::pair<TreeNode *, int> > Q;
            Q.push({root, sum - root->val});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                auto node = current.first;
                int val = current.second;
                if (node->left == NULL && node->right == NULL) {
                    if (val == 0)
                        return true;
                }
                if (node->left != NULL)
                    Q.push({node->left, val - node->left->val});
                if (node->right != NULL)
                    Q.push({node->right, val - node->right->val});
                
            }
            return false;
        }
};

int main(void) {
    Solution s;
}