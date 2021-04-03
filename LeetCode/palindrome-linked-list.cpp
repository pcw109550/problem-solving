// 234. Palindrome Linked List
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
        bool isPalindrome(ListNode* head) {
            // Time O(N) Space O(1)
            int N = 1;
            ListNode *a = head, *b = head;
            while (b->next) {
                b = b->next;
                N++;
                if (b->next) {
                    a = a->next;
                    b = b->next;
                    N++;
                } else
                    break;
            }
            ListNode *s = a->next;
            ListNode *c = head, *d = head->next;
            c->next = NULL;
            for (int i = 0; i < (N - 1) / 2; i++) {
                ListNode *t = d->next;
                d->next = c;
                c = d;
                d = t;
            }
            ListNode *h = c;
            if (N % 2)
                h = h->next;
            for (int i = 0; i < N / 2; i++) {
                if (s->val != h->val)
                    return false;
                s = s->next;
                h = h->next;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}