// 987. Vertical Order Traversal of a Binary Tree
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
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
    std::map<int, std::map<int, std::set<int> > > nodes;
    public:
        std::vector<std::vector<int> > verticalTraversal(TreeNode* root) {
            // O(N * log(N))
            traverse(root, 0, 0);
            std::vector<std::vector<int> > ans;
            for (auto p : nodes) {
                std::vector<int> col;
                for (auto q : p.second) {
                    col.insert(col.end(), q.second.begin(), q.second.end());
                }
                ans.push_back(col);
            }
            return ans;
        }

        void traverse(TreeNode* root, int x, int y) {
            if (root) {
                nodes[x][y].insert(root -> val);
                traverse(root->left, x - 1, y + 1);
                traverse(root->right, x + 1, y + 1);
            }
        }
};

int main(void) {
    Solution s;
}