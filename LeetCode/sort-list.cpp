// 148. Sort List
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>

class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            // O(N log(N))
            if (head == NULL || head->next == NULL)
                return head;
            int N = 0;
            auto current = head;
            while (current != NULL) {
                current = current->next;
                N++;
            }
            current = head;
            for (int i = 0; i < N / 2 - 1; i++) {
                current = current->next;
            }
            auto start = current->next;
            current->next = NULL;
            current = head;
            auto a = sortList(head);
            auto b = sortList(start);
            return merge(a, b);
        }
    
        ListNode* merge(ListNode *a, ListNode *b) {
            // O(N)
            if (a == NULL)
                return b;
            if (b == NULL)
                return a;
            auto current = a->val < b->val ? a : b;
            auto head = current;
            if (a == current)
                a = a->next;
            else if (b == current)
                b = b->next;
            while (a != NULL || b != NULL) {
                if (a == NULL) {
                    current->next = b;
                    b = b->next;
                } else if (b == NULL) {
                    current->next = a;
                    a = a->next;
                } else {
                    current->next = a->val < b->val ? a : b;
                    if (a == current->next)
                        a = a->next;
                    else if (b == current->next)
                        b = b->next;
                }
                current = current->next;
            }
            current->next = NULL;
            return head;
        }
};

int main(void) {
    Solution s;
}