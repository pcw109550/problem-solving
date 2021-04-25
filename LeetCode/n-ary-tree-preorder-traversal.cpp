// 589. N-ary Tree Preorder Traversal
#include <iostream>
#include <vector>
#include <queue>


class Node {
    public:
        int val;
        std::vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, std::vector<Node*> _children) {
            val = _val;
            children = _children;
    }
};

class Solution {
    public:
        std::vector<int> preorder(Node* root) {
            // O(N) iterative
            std::vector<int> result;
            if (!root)
                return result;
            std::deque<Node *> Q;
            Q.push_back(root);
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop_front();
                result.push_back(cur->val);
                if (!cur->children.size())
                    continue;
                for (int i = cur->children.size() - 1; i >= 0; i--)
                    Q.push_front(cur->children[i]);   
            }
            return result;
        }
};

class Solution2 {
    std::vector<int> result;
    public:
        std::vector<int> preorder(Node* root) {
            // O(N) recursive
            if (root)
                traversal(root);
            return result;
        }
    
        void traversal(Node *node) {
            result.push_back(node->val);
            for (auto it : node->children)
                traversal(it);
        }
};

int main(void) {
    Solution s;
}