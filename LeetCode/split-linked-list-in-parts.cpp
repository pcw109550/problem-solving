// 725. Split Linked List in Parts
#include <iostream>
#include <vector>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // O(N)
        vector<ListNode* > result;
        int N = getLength(head);
        int L = N / k;
        int R = N - k * L;
        auto probe = head;
        for (int i = 0; i < k; i++) {
            ListNode *dummy = new ListNode(-1);
            auto p = dummy;
            for (int j = 0; j < L + (i < R); j++) {
                p->next = probe;
                p = p->next;
                probe = probe->next;
            }
            p->next = NULL;
            result.push_back(dummy->next);
            delete dummy;
        }
        return result;
    }
    
    inline int getLength(ListNode *node) {
        int length = 0;
        while (node != NULL) {
            node = node->next;
            length++;
        }
        return length;
    }
};

int main(void) {
    Solution s;
}