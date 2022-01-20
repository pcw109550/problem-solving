// 700. Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        // O(N)
        return traversal(root, val);
    }
    
    TreeNode* traversal(TreeNode* node, int val) {
        if (node == NULL)
            return NULL;
        if (node->val == val)
            return node;
        if (node->val < val)
            return traversal(node->right, val);
        return traversal(node->left, val);
    }
};

int main(void) {
    Solution s;
}
