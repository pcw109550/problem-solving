// 144. Binary Tree Preorder Traversal
#include <iostream>
#include <vector>
#include <stack>

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
        std::vector<int> preorderTraversal(TreeNode* root) {
            // O(N) Iterative
            std::vector<int> result;
            if (root == NULL)
                return result;
            std::stack<TreeNode *> S;
            S.push(root);
            while (!S.empty()) {
                auto current = S.top(); S.pop();
                result.emplace_back(current->val);
                if (current->right != NULL)
                    S.push(current->right);
                if (current->left != NULL)
                    S.push(current->left);
            }
            return result;
        }
};

class Solution2 {
    std::vector<int> result;
    public:
        std::vector<int> preorderTraversal(TreeNode* root) {
            // O(N) Recursive
            if (root != NULL)
                preorder(root);
            return result;
        }
    
        void preorder(TreeNode *node) {
            result.emplace_back(node->val);
            if (node->left != NULL)
                preorder(node->left);
            if (node->right != NULL)
                preorder(node->right);
        }
};

int main(void) {
    Solution s;
}