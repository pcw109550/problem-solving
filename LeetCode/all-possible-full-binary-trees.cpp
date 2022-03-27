// 894. All Possible Full Binary Trees
#include <iostream>
#include <unordered_map>
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
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        // O(N ** 2)
        if (n % 2 == 0)
            return vector<TreeNode *> ();
        unordered_map<int, vector<TreeNode *> > M;
        TreeNode *root = new TreeNode();
        M[1].push_back(root);
        for (int i = 3; i <= n; i += 2) {
            for (int j = 1; j <= i - 1; j += 2) {
                auto l = M[j];
                auto r = M[i - 1 - j];
                for (auto ll : l)
                    for (auto rr : r) {
                        TreeNode *root = new TreeNode();
                        root->left = ll;
                        root->right = rr;
                        M[i].push_back(root);
                    }
            }
        }
        return M[n];
    }
};

int main(void) {
    Solution s;
}
