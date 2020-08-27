// 83. Remove Duplicates from Sorted List
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
        ListNode* deleteDuplicates(ListNode* head) {
            // O(N)
            if (head == NULL)
                return NULL;
            ListNode *probe = head;
            ListNode *probe2 = head;
            while (probe != NULL && probe2 != NULL) {
                if (probe->val != probe2->val) {
                    probe2 = probe2->next;
                    probe2->val = probe->val;
                }
                probe = probe->next;
            }
            probe = probe2->next;
            probe2->next = NULL;
            while (probe != NULL) {
                probe2 = probe->next;
                probe->next = NULL;
                probe = probe2;
            }
            return head;
        }
};

int main(void) {
    ListNode *head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    Solution s;
    ListNode *result = s.deleteDuplicates(head);
    while (result != NULL) {
        std::cout << result->val << ' ';
        result = result->next;
    }
}