// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
#include <iostream>
#include <queue>
#include <utility>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
            // O(N)
            std::queue<std::pair<TreeNode *, TreeNode *> > Q;
            Q.push({original, cloned});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                if (current.first == target)
                    return current.second;
                if (current.first->left != NULL)
                    Q.push({current.first->left, current.second->left});
                if (current.first->right != NULL)
                    Q.push({current.first->right, current.second->right});    
            }
            return NULL;
        }
};

int main(void) {
    Solution s;
}