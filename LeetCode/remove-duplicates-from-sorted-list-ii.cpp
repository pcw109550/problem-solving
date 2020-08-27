// 82. Remove Duplicates from Sorted List II
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
            ListNode *probe = head, *probe2 = head, *probe3 = head;
            if (probe == NULL)
                return NULL;
            int prev = probe->val - 1;
            while (probe2 != NULL) {
                if (probe2->val != prev && (probe2->next == NULL || probe2->val != probe2->next->val)) {
                    probe->val = probe2->val;
                    probe3 = probe;
                    probe = probe->next;
                }
                prev = probe2->val;
                probe2 = probe2->next;
            }  
            if (probe == head)
                return NULL;
            probe3->next = NULL;
            while (probe != NULL) {
                probe3 = probe->next;
                delete probe;
                probe = probe3;
            }
            return head;
        }
};

int main(void) {
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(2,
                    new ListNode(2, new ListNode(3, new ListNode(3)))))));
    ListNode *result = s.deleteDuplicates(head);
    while (result != NULL) {
        std::cout << result->val << ' ';
        result = result->next;
    }
}