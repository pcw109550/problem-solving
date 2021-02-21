// 1302. Deepest Leaves Sum 
#include <iostream>
#include <vector>

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
        int deepestLeavesSum(TreeNode *root) {
            // O(N)
            std::vector<TreeNode *> current, temp;
            current.push_back(root);
            int result;
            while (!current.empty()) {
                result = 0;
                for (auto cur : current) {
                    result += cur->val; 
                    if (cur->left)
                        temp.push_back(cur->left);
                    if (cur->right)
                        temp.push_back(cur->right);
                }
                current = temp;
                temp.clear();
            }
            return result;
        }
};

int main(void) {
    Solution s;
}