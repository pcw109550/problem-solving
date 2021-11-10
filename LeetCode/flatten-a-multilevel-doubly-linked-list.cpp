// 430. Flatten a Multilevel Doubly Linked List
#include <iostream>
using namespace std;

class Node {
public:
    Node(int _val) {
        val = _val;
    }
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    Node* result, *node;
public:
    Node* flatten(Node* head) {
        // O(N)
        if (head == NULL)
            return NULL;
        node = new Node(-1);
        auto temp = node;
        traversal(head);
        auto result = temp->next;
        delete temp;
        result->prev = NULL;
        return result;
    }
    
    void traversal(Node *cur) {
        auto cur_node = new Node(cur->val);
        node->next = cur_node;
        cur_node->prev = node;
        node = cur_node;
        if (cur->child != NULL)
            traversal(cur->child);
        if (cur->next != NULL)
            traversal(cur->next);
    }
};

int main(void) {
    Solution s;
}