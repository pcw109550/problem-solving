// 106. Construct Binary Tree from Inorder and Postorder Traversal
#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> M;
    int N;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // O(N)
        N = inorder.size();
        for (int i = 0; i < N; i++)
            M[inorder[i]] = i;
        auto result = traversal(postorder, 0, N - 1, 0, N - 1);
        return result;
    }
    
    TreeNode* traversal(vector<int> &postorder, int start, int end, int s, int e) {
        if (start > end)
            return NULL;
        int val = postorder[end];
        TreeNode* cur = new TreeNode(val);
        int cur_idx = M[postorder[end]];
        int length = e - cur_idx;
        cur->left = traversal(postorder, start, end - length - 1, s, cur_idx - 1);
        cur->right = traversal(postorder, end - length, end - 1, cur_idx + 1, e);
        return cur;
    }
};

int main(void) {
    Solution s;
}