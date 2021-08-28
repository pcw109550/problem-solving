// 1448. Count Good Nodes in Binary Tree
#include <algorithm>
#include <iostream>
#include <climits>
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
    int goodNodes(TreeNode* root) {
        // O(N)
        result = 0;
        traversal(root, INT_MIN);
        return result;
    }
    
    void traversal(TreeNode *node, int m) {
        if (node->val >= m)
            result++;
        if (node->left != NULL)
            traversal(node->left, max(m, node->val));
        if (node->right != NULL)
            traversal(node->right, max(m, node->val));
    }
};

int main(void) {
    Solution s;
}