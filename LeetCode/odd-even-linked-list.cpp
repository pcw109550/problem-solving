// 328. Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        // Time O(N) Space O(1)
        ListNode *odd_head = new ListNode(-1);
        ListNode *even_head = new ListNode(-1);
        ListNode *o = odd_head, *e = even_head;
        ListNode *op, *ep = head;
        auto it = head;
        int cnt = 0;
        while (it != NULL) {
            cnt++;
            if (cnt % 2 == 1) {
                o->next = ep;
                op = ep->next;
                o = ep;
            } else {
                e->next = op;
                ep = op->next;
                e = op;
            }
            it = it->next;
        }
        if (cnt % 2 == 1)
            e->next = op;
        o->next = even_head->next;
        return odd_head->next;
    }
};

int main(void) {
    Solution s;
}