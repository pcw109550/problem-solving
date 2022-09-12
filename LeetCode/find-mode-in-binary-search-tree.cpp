#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> M;
    int Max;
public:
    vector<int> findMode(TreeNode* root) {
        // O(N)
        traversal(root);
        vector<int> result;
        for (auto it : M)
            if (it.second == Max)
                result.push_back(it.first);
        return result;
    }
    
    void traversal(TreeNode* node) {
        M[node->val]++;
        Max = max(Max, M[node->val]);
        if (node->left)
            traversal(node->left);
        if (node->right)
            traversal(node->right);
    }
};