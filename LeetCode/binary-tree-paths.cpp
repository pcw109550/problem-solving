// 257. Binary Tree Paths
#include <iostream>
#include <vector>
#include <string>
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
    vector<string> result;
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            // O(N ** 2)
            traversal(root, vector<int>());
            return result;
        }
    
        void traversal(TreeNode *node, vector<int> path) {
            path.push_back(node->val);
            if (node->left == NULL && node->right == NULL) {
                string temp;
                for (int i = 0; i < path.size(); i++) {
                    temp += to_string(path[i]);
                    if (i != path.size() - 1)
                        temp += "->";
                }
                result.push_back(temp);
                return;
            }
            if (node->left != NULL)
                traversal(node->left, path);
            if (node->right != NULL)
                traversal(node->right, path);
        }
};

int main(void) {
    Solution s;
}