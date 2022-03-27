// 662. Maximum Width of Binary Tree
#include <algorithm>
#include <iostream>
#include <climits>
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
    vector<pair<long long, long long> > span;
    vector<long long> base;
    long long H = 0;
public:
    int widthOfBinaryTree(TreeNode* root) {
        // O(N)
        long long result = 1;
        span = vector<pair<long long, long long> > (3003, {INT_MAX, INT_MIN});
        base = vector<long long> (3003);
        traversal(root, 0, 0);
        for (int i = 0; i <= H; i++)
            result = max(result, span[i].second - span[i].first + 1);
        return result;
    }
    
    void traversal(TreeNode *node, long long k, long long h) {
        H = max(H, h);
        if (span[h].first == INT_MAX)
            base[h] = k;
        span[h].first = min(span[h].first, k);
        span[h].second = max(span[h].second, k);
        if (node->left != NULL)
            traversal(node->left, 2 * k - base[h], h + 1);
        if (node->right != NULL)
            traversal(node->right, 2 * k + 1 - base[h], h + 1);
    }
};

int main(void) {
    Solution s;
}
