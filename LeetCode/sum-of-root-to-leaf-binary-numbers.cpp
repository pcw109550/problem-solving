// 1022. Sum of Root To Leaf Binary Numbers
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
    int sumRootToLeaf(TreeNode* root) {
        // O(N)
        traversal(root, root->val);
        return result;
    }
    
    void traversal(TreeNode *node, int cur) {
        if (node->left == NULL && node->right == NULL) {
            result += cur;
            return;
        }
        if (node->left)
            traversal(node->left, 2 * cur + node->left->val);
        if (node->right)
            traversal(node->right, 2 * cur + node->right->val);
    }
};

int main(void) {
    Solution s;
}
