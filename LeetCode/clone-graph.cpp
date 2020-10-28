// 133. Clone Graph
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Node {
    public:
        int val;
        std::vector<Node*> neighbors;
        
        Node() {
            val = 0;
            neighbors = std::vector<Node*>();
        }
        
        Node(int _val) {
            val = _val;
            neighbors = std::vector<Node*>();
        }
        
        Node(int _val, std::vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

class Solution {
    public:
        Node* cloneGraph(Node* node) {
            // O(E)
            if (node == NULL)
                return NULL;
            std::unordered_map<Node *, Node *> mapping; // {old : new}
            std::queue<Node *> Q; Node *result;
            result = new Node(node->val, node->neighbors);
            mapping[node] = result;
            Q.push(result);
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                std::vector<Node *> new_neighbors;
                for (auto neighbor : current->neighbors){
                    if (mapping.find(neighbor) != mapping.end()) {
                        new_neighbors.push_back(mapping[neighbor]);
                    } else {
                        Node *new_node = new Node(neighbor->val, neighbor->neighbors);
                        mapping[neighbor] = new_node;
                        new_neighbors.push_back(new_node);
                        Q.push(new_node);    
                    }
                }
                current->neighbors = new_neighbors;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}