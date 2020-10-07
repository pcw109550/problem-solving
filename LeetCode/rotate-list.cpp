// 61. Rotate List
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
        ListNode* rotateRight(ListNode* head, int k) {
            // O(N)
            if (head == NULL)
                return NULL;
            ListNode *tail = head, *probe = head;
            int len = 1, i = 0;
            while (tail->next != NULL) {
                len++;
                tail = tail->next;
            }
            k %= len;
            for (int i = 0; i < len - 1 - k; i++)
                probe = probe->next;
            if (len == 1 || k == 0)
                return head;
            tail->next = head;
            head = probe->next;
            probe->next = NULL;
            return head;
        }
};

int main(void) {
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 5;
    ListNode *result = s.rotateRight(head, k);
    while (result != NULL) {
        std::cout << result->val << ' ';
        result = result->next;
    }
}