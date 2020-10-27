// 142. Linked List Cycle II
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            // Time O(N) Space O(1)
            if (head == NULL)
                return NULL;
            ListNode *tortoise = head, *hare = head->next;
            ListNode *result = head, *temp = head;
            int cycle_size = 1;
            while (tortoise != hare) {
                if (hare == NULL || hare->next == NULL)
                    return NULL;
                tortoise = tortoise->next;
                hare = hare->next->next;
            }
            tortoise = tortoise->next;
            temp = temp->next;
            while (tortoise != hare) {
                tortoise = tortoise->next;
                temp = temp->next;
            }
            while (temp != result) {
                result = result->next;
                temp = temp->next;
            }
            return result;
        }
};

int main(void) {
    Solution s;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    auto result = s.detectCycle(head);
    std::cout << result->val;
}

// 3 2 0 4 2 0 4 2 0 4
// 2 4 0 2 4 0 2 4 0 2
