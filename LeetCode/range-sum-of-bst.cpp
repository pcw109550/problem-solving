// 938. Range Sum of BST
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
    int result;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // O(N)
        traversal(root, low, high);
        return result;
    }
    
    void traversal(TreeNode* node, int low, int high) {
        if (low <= node->val && node->val <= high)
            result += node->val;
        if (node->left)
            traversal(node->left, low, high);
        if (node->right)
            traversal(node->right, low, high);
    }
};

int main(void) {
    Solution s;
}