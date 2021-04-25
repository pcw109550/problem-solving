// 86. Partition List
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
        ListNode* partition(ListNode* head, int x) {
            // Time O(N) Space O(1)
            auto dummy1 = new ListNode(-1);
            auto dummy2 = new ListNode(-1);
            auto probe = head;
            auto p1 = dummy1, p2 = dummy2;
            while (probe != NULL) {
                if (probe->val < x) {
                    auto t = p1->next;
                    p1->next = probe;
                    auto t2 = probe->next;
                    probe->next = NULL;
                    probe = t2;
                    p1 = p1->next;
                } else {
                    auto t = p2->next;
                    p2->next = probe;
                    auto t2 = probe->next;
                    probe->next = NULL;
                    probe = t2;
                    p2 = p2->next;
                }
            }
            ListNode *result;
            if (dummy1->next != NULL) {
                result = dummy1->next;
                p1->next = dummy2->next;
            } else {
                result = dummy2->next;
            }
            delete dummy1;
            delete dummy2;
            return result;
        }
};

int main(void) {
    Solution s;
}