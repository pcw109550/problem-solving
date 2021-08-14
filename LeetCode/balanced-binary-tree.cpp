// 110. Balanced Binary Tree
#include <algorithm>
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
    bool result;
public:
    bool isBalanced(TreeNode* root) {
        // O(N)
        result = true;
        traversal(root);
        return result;
    }
    
    int traversal(TreeNode *node) {
        if (node == NULL)
            return 0;
        int lh = traversal(node->left);
        int rh = traversal(node->right);
        if (abs(lh - rh) > 1)
            result = false;
        return max(lh, rh) + 1;
    }
};

int main(void) {
    Solution s;
}