// 145. Binary Tree Postorder Traversal
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
        std::vector<int> postorderTraversal(TreeNode* root) {
            // O(N) Iterative using single stack
            std::vector<int> result;
            if (root == NULL)
                return result;
            std::stack<TreeNode *> S;
            TreeNode* current = root, *prev = NULL;
            while (current != NULL || !S.empty()) {
                if (current != NULL) {
                    S.push(current);
                    current = current->left;
                } else {
                    current = S.top();
                    if (current->right == NULL || current->right == prev) {
                        result.emplace_back(current->val);
                        S.pop();
                        prev = current;
                        current = NULL;
                    } else
                        current = current->right;
                }
            }
            return result;
        }
};

class Solution2 {
    public:
        std::vector<int> postorderTraversal(TreeNode* root) {
            // O(N) Iterative using two stacks
            std::vector<int> result;
            if (root == NULL)
                return result;
            std::stack<TreeNode *> S;
            std::stack<int> temp;
            S.push(root);
            while (!S.empty()) {
                auto current = S.top(); S.pop();
                temp.push(current->val);
                if (current->left != NULL)
                    S.push(current->left);
                if (current->right != NULL)
                    S.push(current->right);
            }
            while (!temp.empty()) {
                result.emplace_back(temp.top()); temp.pop();
            }
            return result;
        }
};

class Solution3 {
    std::vector<int> result;
    public:
        std::vector<int> postorderTraversal(TreeNode* root) {
            // O(N) Recursive
            if (root != NULL)
                postorder(root);
            return result;
        }
    
        void postorder(TreeNode *node) {
            if (node->left != NULL)
                postorder(node->left);
            if (node->right != NULL)
                postorder(node->right);
            result.emplace_back(node->val);
        }
};

int main(void) {
    Solution s;
}