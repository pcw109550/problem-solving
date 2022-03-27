// 1457. Pseudo-Palindromic Paths in a Binary Tree
#include <iostream>
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
    int result;
    unordered_map<int, int> M;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        // O(N)
        result = 0;
        M[root->val]++;
        traversal(root);
        M[root->val]--;
        return result;        
    }
    
    void traversal(TreeNode *node) {
        if (node->left == NULL && node->right == NULL) {
            int odd_cnt = 0, even_cnt = 0;
            for (auto it : M) {
                if (it.second % 2 == 0)
                    even_cnt++;
                else
                    odd_cnt++;
            }
            result += (odd_cnt == 0 || odd_cnt == 1);
            return;
        }   
        if (node->left != NULL) {
            M[node->left->val]++;
            traversal(node->left);
            M[node->left->val]--;
        }
        if (node->right != NULL) {
            M[node->right->val]++;
            traversal(node->right);
            M[node->right->val]--;
        }
    }
};

int main(void) {
    Solution s;
}
