// 437. Path Sum III
#include <iostream>
#include <unordered_map>
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
        int pathSum(TreeNode* root, int targetSum) {
            // O(N)
            result = 0;
            if (root == NULL)
                return result;
            unordered_map<long long, int> M;
            M[0] = 1;
            traversal(M, targetSum, 0, root);
            return result;
        }
    
        void traversal(unordered_map<long long, int> &M, long long targetSum, long long sum, TreeNode *node) {
            result += M.count(sum + node->val - targetSum) ? M[sum + node->val - targetSum] : 0;
            M[sum + node->val]++;
            if (node->left != NULL)
                traversal(M, targetSum, sum + node->val, node->left);
            if (node->right != NULL)
                traversal(M, targetSum, sum + node->val, node->right);
            M[sum + node->val]--;
        }
};

int main(void) {
    Solution s;
}