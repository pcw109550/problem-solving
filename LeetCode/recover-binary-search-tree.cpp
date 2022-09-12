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
    vector<TreeNode *> nodes;
    TreeNode *temp;
    TreeNode *prev_node;
public:
    void recoverTree(TreeNode* root) {
        // Time O(N) Space O(1)
        traversal(root);
        swap(nodes[0]->val, temp->val);
    }
    
    void traversal(TreeNode *node) {
        if (node->left)
            traversal(node->left);
        if (node->val < (prev_node ? prev_node->val : INT_MIN)) {
            nodes.push_back(prev_node);
            temp = node;
        }
        prev_node = node;
        if (node->right)
            traversal(node->right);
    }
};

class Solution2 {
    vector<TreeNode *> nodes;
public:
    void recoverTree(TreeNode* root) {
        // Time O(N) Space O(N)
        traversal(root);
        vector<int> idxs;
        int N = nodes.size();
        for (int i = 0; i < N - 1; i++)
            if (nodes[i]->val > nodes[i + 1]->val)
                idxs.push_back(i);
        if (idxs.size() == 2)
            swap(nodes[idxs[0]]->val, nodes[idxs[1] + 1]->val);
        else
            swap(nodes[idxs[0]]->val, nodes[idxs[0] + 1]->val);
    }
    
    void traversal(TreeNode *node) {
        if (node->left)
            traversal(node->left);
        nodes.push_back(node);
        if (node->right)
            traversal(node->right);
    }
};

