// 653. Two Sum IV - Input is a BST
#include <iostream>
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
    bool findTarget(TreeNode* root, int k) {
        // O(N)
        return traversal(root, root, k);
    }
    
    bool traversal(TreeNode *a, TreeNode *b, int k) {
        if (a == NULL || b == NULL)
            return false;
        if (a == b)
            return traversal(a, a->right, k) || traversal(a->left, a, k);
        int sum = a->val + b->val;
        if (sum == k)
            return true;
        else if (sum > k)
            return traversal(a->left, b, k) || traversal(a, b->left, k);
        else if (sum < k)
            return traversal(a->right, b, k) || traversal(a, b->right, k);
        else
            return false;
    }
};

int main(void) {
    Solution s;
}