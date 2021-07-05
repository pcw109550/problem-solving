// 687. Longest Univalue Path
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int result = 0;
    public:
        int longestUnivaluePath(TreeNode* root) {
            // O(N)
            if (root != NULL)
                 traversal(root);
            return result;
        }
    
        pair<int, int> traversal(TreeNode *node) {
            if (node->left == NULL && node->right == NULL)
                return {node->val, 0};
            if (node->left == NULL && node->right != NULL) {
                auto it = traversal(node->right);
                if (it.first == node->val) {
                    result = max(result, it.second + 1);
                    return {node->val, it.second + 1};
                }
                return {node->val, 0};
            }
            if (node->left != NULL && node->right == NULL) {
                auto it = traversal(node->left);
                if (it.first == node->val) {
                    result = max(result, it.second + 1);
                    return {node->val, it.second + 1};
                }
                return {node->val, 0};
            }
            auto l = traversal(node->left);
            auto r = traversal(node->right);
            int next = 0;
            if (l.first == node->val)
                next = max(next, l.second + 1);
            if (r.first == node->val)
                next = max(next, r.second + 1);
            result = max(result, next);
            if (l.first == node->val && r.first == node->val)
                result = max(result, l.second + r.second + 2);
            return {node->val, next};
        }
};

int main(void) {
    Solution s;
}