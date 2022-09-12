#include <iostream>
#include <vector>
#include <unordered_set>
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
    vector<TreeNode *> result;
    unordered_set<int> S;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // O(N)
        for (auto it : to_delete)
            S.insert(it);
        traversal(root, true);
        return result;
    }
    
    void traversal(TreeNode *node, bool is_parent_null) {
        if (node == NULL)
            return;
        int val = node->val;
        if (!S.count(val) && is_parent_null)
            result.push_back(node);
        auto l = node->left, r = node->right;
        if (l) {
            if (S.count(l->val)) {
                node->left = NULL; 
                traversal(l->left, true);
                traversal(l->right, true);
            } else {
                traversal(l, S.count(val));   
            }
        }
        if (r) {
            if (S.count(r->val)) {
                node->right = NULL; 
                traversal(r->left, true);
                traversal(r->right, true);
            } else {
                traversal(r, S.count(val));   
            }
        }
    }
};