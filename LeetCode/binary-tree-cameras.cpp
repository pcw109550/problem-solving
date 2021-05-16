// 968. Binary Tree Cameras
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
        int minCameraCover(TreeNode* root) {
            // O(N)
            if (traverse(root) == 1)
                result++;
            return result;
        }
    
        int traverse(TreeNode *root) {
            if (root->left == NULL && root->right == NULL) {
                return 1;
            } else if (root->left != NULL && root->right == NULL) {
                int l = traverse(root->left);
                if (l == 1) {
                    result++;
                    return 2;
                }
                if (l == 2)
                    return 3;
                if (l == 3)
                    return 1;
            } else if (root->right != NULL && root->left == NULL) {
                int r = traverse(root->right);
                if (r == 1) {
                    result++;
                    return 2;
                }
                if (r == 2)
                    return 3;
                if (r == 3)
                    return 1;
            } else {
                int l = traverse(root->left);
                int r = traverse(root->right);
                if (l == 1 || r == 1) {
                    result++;
                    return 2;
                }
                if (l == 2 || r == 2)
                    return 3;
                if (l == 3 || r == 3)
                    return 1;
            }
            return -1;
        }
};

int main(void) {
    Solution s;
}