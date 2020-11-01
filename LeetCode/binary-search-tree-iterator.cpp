// 173. Binary Search Tree Iterator
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    TreeNode *it;
    std::stack<TreeNode *> S;
    public:
        BSTIterator(TreeNode* root) {
            it = root;
        }

        int next() {
            // Average O(1)
            while (it != nullptr) {
                S.push(it);
                it = it->left;
            }
            it = S.top(); S.pop();      
            auto val = it->val;
            it = it->right;
            return val;
        }
        
        bool hasNext() {
            return it != nullptr || !S.empty();
        }
};

int main(void) {
}