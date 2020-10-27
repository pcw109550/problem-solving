// 141. Linked List Cycle
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            // Time O(N) Space O(1)
            if (head == NULL) 
                return false;
            ListNode *tortoise = head, *hare = head->next;
            while (tortoise != hare) {
                if (hare == NULL || hare->next == NULL)
                    return false;
                tortoise = tortoise->next;
                hare = hare->next->next;
            }
            return true;
        }
};

int main(void) {
    Solution s;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    bool result = s.hasCycle(head);
    std::cout << result;
}