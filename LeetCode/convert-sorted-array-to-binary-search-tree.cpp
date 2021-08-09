// 108. Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // O(N)
        int N = nums.size();
        auto result = traversal(nums, 0, N - 1);
        return result;
    }
    
    TreeNode* traversal(vector<int>& nums, int b, int e) {
        if (b > e)
            return NULL;
        int m = (b + e) / 2;
        TreeNode *result = new TreeNode(nums[m]);
        result->left = traversal(nums, b, m - 1);
        result->right = traversal(nums, m + 1, e);
        return result;
    }
};

int main(void) {
    Solution s;
}