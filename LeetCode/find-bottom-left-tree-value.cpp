// 513. Find Bottom Left Tree Value
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
public:
    int findBottomLeftValue(TreeNode* root) {
        // O(N)
        vector<TreeNode *> cur, temp;
        int result = -1;
        cur.push_back(root);
        while (!cur.empty()) {
            temp.clear();
            result = cur[0]->val;
            for (auto n : cur) {
                if (n->left != NULL)
                    temp.push_back(n->left);
                if (n->right != NULL)
                    temp.push_back(n->right);
            }
            cur.clear();
            cur = temp;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}