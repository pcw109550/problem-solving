// 147. Insertion Sort List
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
        ListNode* insertionSortList(ListNode* head) {
            // O(N ** 2)
            if (head == NULL || head->next == NULL)
                return head;
            ListNode *probe = head->next, *start = head, *curr_prev = head, *prev, *temp, *current, *iter;
            while (probe != NULL) {
                current = probe; iter = start;
                prev = NULL;
                temp = probe->next;
                while (iter->val < current->val) {
                    prev = iter;
                    iter = iter->next;
                }
                if (iter == probe) {
                    curr_prev = curr_prev->next;
                    probe = probe->next;
                    continue;
                }
                curr_prev->next = current->next;
                current->next = iter;
                if (prev == NULL)
                    start = current;
                else
                    prev->next = current;
                probe = temp;
            }
            return start;
    }
};

int main(void) {
    Solution s;
}