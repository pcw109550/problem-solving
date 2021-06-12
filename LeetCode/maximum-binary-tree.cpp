// 654. Maximum Binary Tree
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
        TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
            // O(N ** 2)
            return traverse(0, nums.size() - 1, nums);
        }
    
        TreeNode* traverse(int l, int r, std::vector<int>& nums) {
            if (l > r)
                return NULL;
            int idx = -1;
            int Max = INT_MIN;
            for (int i = l; i <= r; i++)
                if (Max < nums[i]) {
                    Max = nums[i];
                    idx = i;
                }
            TreeNode *result = new TreeNode(nums[idx]);
            result->left = traverse(l, idx - 1, nums);
            result->right = traverse(idx + 1, r, nums);
            return result;
        }
};

int main(void) {
    Solution s;
}