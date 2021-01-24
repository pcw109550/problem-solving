// 1305. All Elements in Two Binary Search Trees
#include <iostream>
#include <stack>
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
    
    public:
        std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
            // O(N)
            std::vector<int> result;
            auto a = inorder(root1);
            auto b = inorder(root2);
            int p1 = 0, p2 = 0;
            while (p1 < a.size() || p2 < b.size()) {
                if (p1 == a.size()) {
                    result.push_back(b[p2]);
                    p2++;
                    continue;
                }
                if (p2 == b.size()) {
                    result.push_back(a[p1]);
                    p1++;
                    continue;
                }
                if (a[p1] < b[p2]) {
                    result.push_back(a[p1]);
                    p1++;
                } else {
                    result.push_back(b[p2]);
                    p2++;
                }
            }
            return result;
        }
    
        std::vector<int> inorder(TreeNode *root) {
            std::vector<int> result;
            if (root == NULL)
                return result;
            std::stack<TreeNode *> S;
            auto current = root;
            while (!S.empty() || current != NULL) {
                if (current != NULL) {
                    S.push(current);
                    current = current->left;
                } else {
                    current = S.top(); S.pop();
                    result.push_back(current->val);
                    current = current->right;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}