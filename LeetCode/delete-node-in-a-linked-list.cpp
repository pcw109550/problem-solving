// 237. Delete Node in a Linked List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        void deleteNode(ListNode* node) {
            // O(N)
            auto current = node;
            ListNode *prev;
            while (current->next != NULL) {
                current->val = current->next->val;
                prev = current;
                current = current->next;
            }
            prev->next = NULL;
            delete current;
        }
};

int main(void) {
    Solution s;
}