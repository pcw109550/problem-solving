// 129. Sum Root to Leaf Numbers
#include <iostream>

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
        int sumNumbers(TreeNode *root) {
            // O(N)
            if (root)
                traversal(root, 0);
            return result;
        }
    
        void traversal(TreeNode *node, int acc) {
            int next = 10 * acc + node->val;
            if (node->left == NULL && node->right == NULL) {
                result += next;
                return;
            }
            if (node->left != NULL)
                traversal(node->left, next);
            if (node->right != NULL)
                traversal(node->right, next);
            return;
        }
};

int main(void) {
    Solution s;
}