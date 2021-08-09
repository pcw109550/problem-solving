// 814. Binary Tree Pruning
#include <iostream>
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
public:
    TreeNode* pruneTree(TreeNode* root) {
        // O(N)
        int t = traversal(root);
        return t == 0 ? NULL : root;
    }
    
    int traversal(TreeNode* node) {
        int sum = node->val;
        if (node->left != NULL) {
            int l = traversal(node->left);
            if (l == 0) {
                delete node->left;
                node->left = NULL;
            }
            sum += l;
        }
        if (node->right != NULL) {
            int r = traversal(node->right);
            if (r == 0) {
                delete node->right;
                node->right = NULL;
            }
            sum += r;
        }
        return sum;
    }
};

int main(void) {
    Solution s;
}