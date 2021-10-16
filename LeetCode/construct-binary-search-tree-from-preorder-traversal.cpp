// 1008. Construct Binary Search Tree from Preorder Traversal
#include <iostream>
#include <vector>
#include <climits>
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
    int idx;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder, int p_val = INT_MAX) {
        // O(N)
        if (idx >= preorder.size() || preorder[idx] > p_val)
            return NULL;
        auto n = new TreeNode(preorder[idx++]);
        n->left = bstFromPreorder(preorder, n->val);
        n->right = bstFromPreorder(preorder, p_val);
        return n;
    }
};

int main(void) {
    Solution s;
}