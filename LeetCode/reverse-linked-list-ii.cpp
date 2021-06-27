// 92. Reverse Linked List II
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            // Time O(N) Space O(1)
            ListNode* dummy = new ListNode(-501, head);
            auto probe = dummy;
            ListNode *l, *r;
            for (int i = 0; i < right; i++) {
                if (i == left - 1)
                    l = probe;
                if (i == right - 1)
                    r = probe;
                probe = probe->next;
            }
            auto back = r->next->next;
            auto end = r->next;
            probe = l->next;
            for (int i = left; i <= right; i++) {
                auto temp = probe->next;
                probe->next = back;
                back = probe;
                probe = temp;
            }
            l->next = end;
            ListNode *result = dummy->next;
            delete dummy;
            return result;
        }
};

int main(void) {
    Solution s;
}