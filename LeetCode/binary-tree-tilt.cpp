// 563. Binary Tree Tilt
#include <iostream>
#include <cmath>
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
    int findTilt(TreeNode* root) {
        // O(N)
        traversal(root);
        return result;
    }
    
    int traversal(TreeNode* node) {
        if (node == NULL)
            return 0;
        int lsum = 0, rsum = 0;
        if (node->left != NULL)
            lsum = traversal(node->left);
        if (node->right != NULL)
            rsum = traversal(node->right);
        result += abs(lsum - rsum);
        return lsum + node->val + rsum;
    }
};

int main(void) {
    Solution s;
}
