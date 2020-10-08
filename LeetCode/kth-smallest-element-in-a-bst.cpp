// 230. Kth Smallest Element in a BST
#include <iostream>
#include <stack>
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
    public:
        int kthSmallest(TreeNode* root, int k) {
            // O(N) iterative
            std::vector<int> data;
            std::stack<TreeNode *> S;
            TreeNode *current = root;
            while (true) {
                while (current != NULL) {
                    S.push(current);
                    current = current->left;
                }
                if (S.empty())
                    break;
                data.emplace_back(S.top()->val);
                current = S.top(); S.pop();
                current = current->right;
            }
            return data[k - 1];
        }
};

class Solution2 {
    std::vector<int> data;
    public:
        int kthSmallest(TreeNode* root, int k) {
            // O(N) recursive
            inorder(root);
            return data[k - 1];
        }

        void inorder(TreeNode *node) {
            if (node == NULL)
                return;
            inorder(node->left);
            data.emplace_back(node->val);
            inorder(node->right);
        }
};

int main(void) {
    Solution s;
}