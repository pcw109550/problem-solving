// 105. Construct Binary Tree from Preorder and Inorder Traversal
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int idx = 0;
        std::vector<int> _preorder;
        std::unordered_map<int, int> pos;
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
            // O(N)
            _preorder = preorder;
            for (int i = 0; i < inorder.size(); i++)
                pos[inorder[i]] = i;
            TreeNode *root = recover(0, preorder.size());
            return root;
        }
    
        TreeNode* recover(int start, int end) {
            if (start == end)
                return NULL;
            int cur_pos = pos[_preorder[idx]];
            if (cur_pos < start || cur_pos >= end)
                return NULL;
            TreeNode *node = new TreeNode(_preorder[idx++]);
            node->left = recover(start, cur_pos);
            node->right = recover(cur_pos + 1, end);
            return node;
        }
};

int main(void) {
    Solution s;
}