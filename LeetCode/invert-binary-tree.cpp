
// 226. Invert Binary Tree
#include <iostream>
#include <queue>

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
        TreeNode* invertTree(TreeNode* root) {
            // O(N) iterative
            if (root == NULL)
                return NULL;
            std::queue<TreeNode *> Q;
            Q.push(root);
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();    
                if (current == NULL)
                    continue;
                std::swap(current->left, current->right);
                Q.push(current->left);
                Q.push(current->right);
            }
            return root;
        }  
};

class Solution2 {
    public:
        TreeNode* invertTree(TreeNode* root) {
            // O(N) recursive
            if (root == NULL)
                return NULL;
            std::swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }  
};

int main(void) {
    Solution s;
}