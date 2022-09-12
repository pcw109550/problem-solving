#include <iostream>
#include <string>
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
    string result;
public:
    string tree2str(TreeNode* root) {
        // O(N)
        traversal(root);
        return result;
    }
    
    void traversal(TreeNode *node) {
        result += to_string(node->val);
        if (node->left == NULL && node->right == NULL)
            return;
        result += string(1, '(');
        if (node->left)
            traversal(node->left);
        result += string(1, ')');
        if (node->right) {
            result += string(1, '('); 
            traversal(node->right);
            result += string(1, ')');
        }
    }
    
    
};