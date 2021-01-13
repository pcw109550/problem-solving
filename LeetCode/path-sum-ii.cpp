// 113. Path Sum II
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
        std::vector<std::vector<int> > pathSum(TreeNode* root, int sum) {
            // O(N)
            std::vector<std::vector<int> > result;
            if (root == NULL)
                return result;
            std::queue<std::pair<TreeNode *, int> > Q;
            std::vector<TreeNode *> result_childs;
            std::unordered_map<TreeNode *, TreeNode *> M;
            M[root] == NULL;
            Q.push({root, sum - root->val});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                auto node = current.first;
                int val = current.second;
                if (node->left == NULL && node->right == NULL) {
                    if (val == 0)
                        result_childs.emplace_back(node);
                }
                if (node->left != NULL) {
                    Q.push({node->left, val - node->left->val});
                    M[node->left] = node;
                }
                if (node->right != NULL) {
                    Q.push({node->right, val - node->right->val});
                    M[node->right] = node;
                }
            }
            for (auto child : result_childs) {
                std::vector<int> trace;
                auto current = child;
                while (current != NULL) {
                    trace.emplace_back(current->val);
                    current = M[current];
                }
                std::reverse(trace.begin(), trace.end());
                result.push_back(trace);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}