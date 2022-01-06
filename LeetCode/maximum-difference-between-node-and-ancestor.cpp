// 1026. Maximum Difference Between Node and Ancestor
#include <algorithm>
#include <iostream>
#include <utility>
#include <cmath>
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
    int result;
public:
    int maxAncestorDiff(TreeNode* root) {
        // O(N)
        result = 0;
        traversal(root);
        return result; 
    }
    
    pair<int, int> traversal(TreeNode* node) {
        pair<int, int> cur = {INT_MIN, INT_MAX};
        if (node->left != NULL) {
            auto l = traversal(node->left);
            cur.first = max(cur.first, l.first);
            cur.second = min(cur.second, l.second);
        }
        if (node->right != NULL) {
            auto r = traversal(node->right);
            cur.first = max(cur.first, r.first);
            cur.second = min(cur.second, r.second);
        }
        if (cur.first != INT_MIN)
            result = max(result, abs(cur.first - node->val));
        if (cur.second != INT_MAX)
            result = max(result, abs(cur.second - node->val));
        cur.first = max(cur.first, node->val);
        cur.second = min(cur.second, node->val);
        return cur;
    }
};

int main(void) {
    Solution s;
}