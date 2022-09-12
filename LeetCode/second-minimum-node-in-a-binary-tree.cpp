#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    long long Min = LLONG_MAX;
    int root_val;
public:
    int findSecondMinimumValue(TreeNode* root) {
        // O(N)
        root_val = root->val;
        traversal(root);
        return Min == LLONG_MAX ? -1 : Min;
    }
    
    void traversal(TreeNode *node) {
        if (node->val != root_val)
            Min = min(Min, static_cast<long long>(node->val));
        if (node->left)
            traversal(node->left);
        if (node->right)
            traversal(node->right);
    }
};