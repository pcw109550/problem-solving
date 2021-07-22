// 559. Maximum Depth of N-ary Tree
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    public:
        int maxDepth(Node* root) {
            // O(N)
            int result = 0;
            if (root == NULL)
                return result;
            vector<Node *> cur, temp;
            cur.push_back(root);
            while (!cur.empty()) {
                temp.resize(0);
                result++;
                for (auto node : cur)
                    for (auto child : node->children)
                        temp.push_back(child);
                cur = temp;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}