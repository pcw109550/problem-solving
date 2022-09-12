#include <iostream>
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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // O(N)
        auto result = traversal(root1, root2);
        return result;
    }
    
    TreeNode* traversal(TreeNode *r1, TreeNode *r2) {
        if (!r1 && !r2)
            return NULL;
        int val = 0;
        if (r1)
            val += r1->val;
        if (r2)
            val += r2->val;
        auto r = new TreeNode(val);
        auto r1l = r1 ? r1->left : NULL;
        auto r1r = r1 ? r1->right : NULL;
        auto r2l = r2 ? r2->left : NULL;
        auto r2r = r2 ? r2->right : NULL;
        if (r1l || r2l)
            r->left = traversal(r1l, r2l);
        if (r1r || r2r)
            r->right = traversal(r1r, r2r);
        return r;
    }
};