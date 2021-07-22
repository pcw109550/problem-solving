// 111. Minimum Depth of Binary Tree
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
        int minDepth(TreeNode* root) {
            // O(N)
            int result = 0;
            if (root == NULL)
                return result;
            vector<TreeNode *> cur, temp;
            cur.push_back(root);
            while (!cur.empty()) {
                temp.resize(0);
                result++;
                for (auto node : cur) {
                    if (node->left == NULL && node->right == NULL)
                        return result;
                    if (node->left != NULL)
                        temp.push_back(node->left);
                    if (node->right != NULL)
                        temp.push_back(node->right);
                }
                cur = temp;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}