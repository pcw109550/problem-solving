// 701. Insert into a Binary Search Tree
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
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            // Time O(log(N)) Space O(1)
            if (root == NULL) {
                root = new TreeNode(val);
                return root;
            }
            TreeNode *pointer = root;
            while (true) {
                if (pointer->val < val) {
                    if (pointer->right == NULL) {
                        pointer->right = new TreeNode(val);
                        break;
                    }
                    pointer = pointer->right;
                } else {
                    if (pointer->left == NULL) {
                        pointer->left = new TreeNode(val);
                        break;
                    }
                    pointer = pointer->left;
                }
            }
            return root;
        }
};

int main(void) {
    Solution s;
}