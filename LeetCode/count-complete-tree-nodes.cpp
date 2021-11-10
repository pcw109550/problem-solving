// 222. Count Complete Tree Nodes
#include <iostream>
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
    int H;
public:
    int countNodes(TreeNode* root) {
        // O(log(N) ** 2)
        if (root == NULL)
            return result;
        result += 1;
        H += 1;
        traversal(root->right, 1);
        auto node = root;
        int h = H;
        while (node != NULL) {
            if (check(node->left, h - 1)) {
                result += 1 << (h - 1);
                h--;
                node = node->right;
            } else {
                h--;
                node = node->left;
            }
        }
        return result;
    }
    
    void traversal(TreeNode *node, int height) {
        // O(log(N))
        if (node != NULL) {
            H = height + 1;
            result += 1 << height;
            traversal(node->right, height + 1);
        }
    }
    
    bool check(TreeNode *node, int height) {
        // O(log(N))
        if (node == NULL)
            return false;
        for (int i = 0; i < height; i++) {
            if (node->right != NULL)
                node = node->right;
            else
                return false;
        }
        return true;
    }
};

int main(void) {
    Solution s;
}