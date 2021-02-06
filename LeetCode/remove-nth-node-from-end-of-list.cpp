// 19. Remove Nth Node From End of List
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // O(N)
            auto p1 = head, p2 = head;
            for (int i = 0; i < n; i++) {
                p2 = p2->next;
            }
            if (p2 == NULL)
                return head->next;
            while (p2->next != NULL) {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1->next = p1->next->next;
            return head;
        }
};

int main(void) {
    Solution s;
}