// 919. Complete Binary Tree Inserter
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
    TreeNode *_root;    
    vector<TreeNode *> nodes;
    int idx;
public:
    CBTInserter(TreeNode* root): idx(0) {
        // O(N)
        vector<TreeNode *> curr, next;
        _root = new TreeNode(root->val);
        nodes.push_back(_root);
        curr.push_back(root);
        while (!curr.empty()) {
            next.clear();
            for (auto it : curr) {
                if (it->left != NULL) 
                    next.push_back(it->left);
                if (it->right != NULL)
                    next.push_back(it->right);
            }
            for (auto it : next)
                insert(it->val);
            curr = next;
        }
    }
    
    int insert(int val) {
        // O(log(N))
        if (idx == nodes.size()) {
            vector<TreeNode *> next;
            for (auto it : nodes) {
                next.push_back(it->left);
                next.push_back(it->right);
            }
            idx = 0;
            nodes = next;
        }
        int result = nodes[idx]->val;
        if (nodes[idx]->left == NULL)
            nodes[idx]->left = new TreeNode(val);
        else if (nodes[idx]->right == NULL) {
            nodes[idx]->right = new TreeNode(val);
            idx++;
        }
        return result;
    }
    
    TreeNode* get_root() {
        // O(1)
        return _root;
    }
};

int main(void) {
    CBTInserter* obj;
}
