// 138. Copy List with Random Pointer
#include <iostream>
#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            // O(N)
            if (head == NULL)
                return NULL;
            int idx = 0;
            Node* dummy = new Node(-1);
            Node* probe = head;
            Node* node = dummy;
            std::unordered_map<Node* , int> M;
            std::vector<Node *> new_nodes;
            while (probe != NULL) {
                node->next = new Node(probe->val);
                node = node->next;
                M[probe] = idx;
                probe = probe->next;
                new_nodes.push_back(node);
                idx++;
            }
            probe = head;
            node = dummy->next;
            while (probe != NULL) {
                if (probe->random != NULL) {
                    int rand_idx = M[probe->random];
                    node->random = new_nodes[rand_idx];
                }
                node = node->next;
                probe = probe->next;
            }            
            Node *result = dummy->next;
            delete dummy;
            return result;
        }
};

int main(void) {
    Solution s;
}