// 1339. Maximum Product of Splitted Binary Tree
#include <algorithm>
#include <iostream>
using namespace std;
#define FIELD 1000000007

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    long long result;
    long long sum;
public:
    int maxProduct(TreeNode* root) {
        // O(N)
        traverse_raw(root);
        traverse(root);
        result %= FIELD;
        return result;
    }
    
    void traverse_raw(TreeNode* node) {
        sum += node->val;
        if (node->left)
            traverse_raw(node->left);
        if (node->right)
            traverse_raw(node->right);
    }
    
    long long traverse(TreeNode* node) {
        long long cur = 0;
        if (node) {
            cur += node->val;
            if (node->left) {
                long long l = traverse(node->left);
                cur += l;
                result = max(result, l * (sum - l));
            }
            if (node->right) {
                long long r = traverse(node->right);
                cur += r;
                result = max(result, r * (sum - r));
            }
        }
        return cur;
    }
};

int main(void) {
    Solution s;
}