// 971. Flip Binary Tree To Match Preorder Traversal
#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int idx = 0;
    bool fail;
    std::vector<int> result;
    public:
        std::vector<int> flipMatchVoyage(TreeNode* root, std::vector<int>& voyage) {
            // O(N)
            preorder(root, voyage);
            return fail ? std::vector<int> {-1} : result;
        }
    
        void preorder(TreeNode *node, std::vector<int>& voyage) {
            if (fail || node->val != voyage[idx]) {
                fail = true;
                return;
            }
            if (voyage.size() == idx)
                return;
            if (node->left && voyage[idx + 1] != node->left->val) {
                std::swap(node->left, node->right);
                result.push_back(node->val);
            }
            idx += 1;
            if (node->left)
                preorder(node->left, voyage);
            if (node->right)
                preorder(node->right, voyage);
        }
};

int main(void) {
    Solution s;
}