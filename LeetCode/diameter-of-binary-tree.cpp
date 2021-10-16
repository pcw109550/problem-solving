// 543. Diameter of Binary Tree
#include <algorithm>
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
    int diameterOfBinaryTree(TreeNode* root) {
        // O(N)
        traversal(root);
        return result;
    }
    
    int traversal(TreeNode *node) {
        int lh = 0, rh = 0;
        if (node->left != NULL)
            lh = traversal(node->left);
        if (node->right != NULL)
            rh = traversal(node->right);
        result = max(result, lh + rh);
        return 1 + max(lh, rh);
    }
};

int main(void) {
    Solution s;
}