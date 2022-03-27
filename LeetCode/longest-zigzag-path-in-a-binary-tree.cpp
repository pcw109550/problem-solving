// 1372. Longest ZigZag Path in a Binary Tree
#include <iostream>
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
    int result = 0;
public:
    int longestZigZag(TreeNode* root) {
        // O(N)
        auto it = traversal(root);
        result = max(result, max(it.first, it.second));
        return result - 1;
    }
    
    pair<int, int> traversal(TreeNode *node) {
        pair<int, int> cur = {1, 1};
        if (node->left != NULL) {
            auto l = traversal(node->left);
            cur.second = max(cur.second, l.first + 1);
        }
        if (node->right != NULL) {
            auto r = traversal(node->right);
            cur.first = max(cur.first, r.second + 1);
        }
        result = max(result, max(cur.first, cur.second));
        return cur;
    }
};

int main(void) {
    Solution s;
}
