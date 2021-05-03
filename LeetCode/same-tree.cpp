// 100. Same Tree
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool result = true;
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            // O(N)
            traversal(p, q);
            return result;
        }
    
        void traversal(TreeNode *p, TreeNode *q) {
            if (!result || (p == NULL && q == NULL))
                return;
            if (p == NULL && q != NULL) {
                result = false;
                return;
            }
            if (p != NULL && q == NULL) {
                result = false;
                return;
            }
            if (p->val != q->val) {
                result = false;
                return;
            }
            traversal(p->left, q->left);
            traversal(p->right, q->right);
        }
};

int main(void) {
    Solution s;
}