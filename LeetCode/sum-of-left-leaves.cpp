// 404. Sum of Left Leaves
#include <iostream>
#include <vector>
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
    int result;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // O(N)
        traversal(root);
        return result;
    }
    
    void traversal(TreeNode* node) {
        if (node->left != NULL) {
            if (node->left->left == NULL && node->left->right == NULL)
                result += node->left->val;
            traversal(node->left);
        }
        if (node->right != NULL)
            traversal(node->right);
    }
};

int main(void) {
    Solution s;
}