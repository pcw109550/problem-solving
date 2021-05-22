// 235. Lowest Common Ancestor of a Binary Search Tree
#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // O(N)
            TreeNode *probe = root;
            if (p->val > q->val)
                std::swap(p, q);
            while (true) {
                int pval = p->val, qval = q->val;
                if (pval == probe->val || qval == probe->val)
                    return probe;
                if (qval < probe->val)
                    probe = probe->left;
                else if (pval > probe->val)
                    probe = probe->right;
                else if (pval < probe->val && probe->val < qval)
                    return probe;
            }
            return NULL;
        }
};

int main(void) {
    Solution s;
}