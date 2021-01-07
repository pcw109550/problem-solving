// 103. Binary Tree Zigzag Level Order Traversal
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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
        std::vector<std::vector<int> > zigzagLevelOrder(TreeNode* root) {
            // O(N)
            std::vector<std::vector<int> > result;
            if (root == NULL)
                return result;
            std::queue<std::pair<TreeNode *, int> > Q;
            Q.push({root, 0});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                if (result.size() < current.second + 1)
                    result.push_back(std::vector<int> {current.first->val});
                else
                    result[current.second].emplace_back(current.first->val);
                if (current.first->left != NULL)
                    Q.push({current.first->left, current.second + 1});
                if (current.first->right != NULL)
                    Q.push({current.first->right, current.second + 1});
            }
            for (int i = 1; i < result.size(); i += 2)
                std::reverse(result[i].begin(), result[i].end());
            return result;
        }
};

int main(void) {
    Solution s;
}