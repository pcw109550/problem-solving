// 206. Reverse Linked List
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* result;
public:
    ListNode* reverseList(ListNode* head) {
        // O(N)
        if (head == NULL)
            return NULL;
        reverse(head, NULL);
        return result;
    }
    
    void reverse(ListNode *node, ListNode *prev) {
        ListNode* next;
        if (node->next != NULL)
            next = node->next;
        else {
            node->next = prev;
            result = node;
            return;
        }
        node->next = prev;
        reverse(next, node);
    }
};

int main(void) {
    Solution s;
}