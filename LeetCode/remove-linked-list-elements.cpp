// 203. Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        // O(N)
        ListNode *dummy = new ListNode(-1, head);
        ListNode *probe = head, *prev = dummy;
        while (probe != NULL) {
            if (probe->val == val) {
                prev->next = probe->next;
                probe = probe->next;   
            } else {
                prev = prev->next;
                probe = probe->next;
            }
        }
        auto result = dummy->next;
        delete dummy;
        return result;
    }
};

int main(void) {
    Solution s;
}
