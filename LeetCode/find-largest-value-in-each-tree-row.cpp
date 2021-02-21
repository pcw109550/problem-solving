// 515. Find Largest Value in Each Tree Row
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

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
        std::vector<int> largestValues(TreeNode* root) {
            // O(N)
            std::vector<int> result;
            if (root == NULL)
                return result;
            std::vector<TreeNode *> current, temp;
            current.push_back(root);
            while (current.size()) {
                int Max = INT_MIN;
                for (auto cur : current) {
                    Max = std::max(Max, cur->val);
                    if (cur->left)
                        temp.push_back(cur->left);
                    if (cur->right)
                        temp.push_back(cur->right);
                }
                current = temp;
                temp.clear();
                result.push_back(Max);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}