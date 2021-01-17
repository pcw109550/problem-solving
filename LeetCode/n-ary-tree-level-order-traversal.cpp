// 429. N-ary Tree Level Order Traversal
#include <iostream>
#include <vector>

class Node {
    public:
        int val;
        std::vector<Node *> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, std::vector<Node *> _children) {
            val = _val;
            children = _children;
    }
};


class Solution {
    public:
        std::vector<std::vector<int> > levelOrder(Node* root) {
            // O(N)
            std::vector<std::vector<int> > result;
            if (root == NULL)
                return result;
            std::vector<Node *> level;
            level.emplace_back(root);
            while(!level.empty()) {
                std::vector<Node *> next_level;
                result.push_back(std::vector<int> ());
                for (auto cur : level) {
                    result.back().emplace_back(cur->val);
                    for (auto child : cur->children)
                        next_level.emplace_back(child);
                }
                level = next_level;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}