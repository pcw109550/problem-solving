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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // O(N)
        vector<TreeNode *> L, R;
        traverse(root, p, L);
        traverse(root, q, R);
        unordered_set<TreeNode *> S;
        for (auto it : L)
            S.insert(it);
        for (auto it : R)
            if (S.count(it))
                return it;
        return NULL;
    }
    
    bool traverse(TreeNode *node, TreeNode *target, vector<TreeNode *> &path) {
        if (node == target) {
            path.push_back(node);
            return true;
        }
        if (node->left != NULL && traverse(node->left, target, path)) {
            path.push_back(node);
            return true;
        }
        if (node->right != NULL && traverse(node->right, target, path)) {
            path.push_back(node);
            return true;
        }
        return false;
    }
};