// 450. Delete Node in a BST
#include <iostream>
#include <climits>
#include <utility>
using namespace std;

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // O(H)
        TreeNode *dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        auto it = search(dummy, dummy->left, key);
        auto parent = it.first;
        auto target = it.second;
        if (target == NULL) {
            delete dummy;
            return root;
        }
        auto left = target->left; // 1
        auto right = target->right; // NULL
        if (parent->left == target) {
            parent->left = right;
            if (parent->left != NULL) {
                auto leftmost = traverse(parent->left);
                leftmost->left = left;
            } else
                parent->left = left;
        } else if (parent->right == target) {
            parent->right = right;
            if (parent->right != NULL) {
                auto leftmost = traverse(parent->right);
                leftmost->left = left;
            } else
                parent->right = left;
        }
        delete target;
        auto result = dummy->left;
        delete dummy;
        return result;
    }
    
    TreeNode *traverse(TreeNode *node) {
        // O(H)
        while (node->left != NULL)
            node = node->left;
        return node;
    }
    
    pair<TreeNode *, TreeNode *> search(TreeNode *parent, TreeNode *target, int key) {
        // O(H)
        if (target == NULL)
            return {NULL, NULL};
        if (target->val == key)
            return {parent, target};
        if (target->val < key)
            return search(target, target->right, key);
        return search(target, target->left, key);
    }
};

int main(void) {
    Solution s;
}