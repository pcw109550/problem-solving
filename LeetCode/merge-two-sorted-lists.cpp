// 21. Merge Two Sorted Lists
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
        ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
            // O(N)
            if (l1 == NULL && l2 == NULL)
                return NULL;
            ListNode *probe = new ListNode();
            ListNode *result = probe;
            while (!(l1 == NULL && l2 == NULL)) {
                if (l1 == NULL) {
                    probe->val = l2->val;
                    l2 = l2->next;
                } else if (l2 == NULL) {
                    probe->val = l1->val;
                    l1 = l1->next;
                } else {
                    if (l1->val < l2->val) {
                        probe->val = l1->val;
                        l1 = l1->next;
                    } else {
                        probe->val = l2->val;
                        l2 = l2->next;
                    }
                }
                if (!(l1 == NULL && l2 == NULL)) {
                    probe->next = new ListNode();
                    probe = probe->next;
                }
            }
            return result;
        }
};

int main(void) {
    ListNode *l1 = new ListNode(0, new ListNode(3, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(6))));
    Solution s;
    ListNode *result = s.mergeTwoLists(l1, l2);
    while (result != NULL) {
        std::cout << result->val << ' ';
        result = result->next;
    }
}