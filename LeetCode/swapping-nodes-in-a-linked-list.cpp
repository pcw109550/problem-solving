// 1721. Swapping Nodes in a Linked List
#include <algorithm>
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
        ListNode* swapNodes(ListNode* head, int k) {
            // Time O(N) Space O(1)
            ListNode *it = head;
            ListNode *first, *second = NULL;
            int cnt = 1;
            while (it) {
                if (second)
                    second = second->next;
                if (cnt == k) {
                    first = it;
                    second = head;
                }
                it = it->next;
                cnt++;
            }
            std::swap(first->val, second->val);
            return head;
        }
};

int main(void) {
    Solution s;
}