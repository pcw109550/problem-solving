// 2. Add Two Numbers
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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            // O(n)
            ListNode *result = new ListNode;
            ListNode *probe = result, *p1 = l1, *p2 = l2;
            int sum = 0;
            while (true) {
                if (p1 != nullptr) {
                    sum += p1->val;
                    p1 = p1->next;
                }
                if (p2 != nullptr) {
                    sum += p2->val;
                    p2 = p2->next;
                }
                probe->val = sum % 10;
                sum /= 10;
                if (!(p1 == nullptr && p2 == nullptr)) {
                    probe->next = new ListNode;
                    probe = probe->next;
                } else
                    break;
            }
            if (sum != 0)
                probe->next = new ListNode(sum);
            return result;
        }
};

int main(void) {
    ListNode l1 (9, new ListNode (7, new ListNode (5)));
    ListNode l2 (6, new ListNode (8, new ListNode (5, new ListNode(9))));
    Solution s;
    ListNode *result = s.addTwoNumbers(&l1, &l2);
    while (result != nullptr) {
        std::cout << result->val << ' ';
        result = result->next;
    }
}