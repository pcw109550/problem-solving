// 24. Swap Nodes in Pairs
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // O(N)
        if (head == NULL || head->next == NULL)
            return head;
        auto result = head->next;
        auto current = head;
        ListNode *prev = NULL;
        while (current != NULL && current->next != NULL) {
            auto temp = current->next;
            current->next = temp->next;
            temp->next = current;
            current = temp->next->next;
            if (prev != NULL)
                prev->next = temp;
            prev = temp->next;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}