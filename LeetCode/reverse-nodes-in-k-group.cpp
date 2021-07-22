// 25. Reverse Nodes in k-Group
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
        ListNode* reverseKGroup(ListNode* head, int k) {
            // Time O(N) Space O(1)
            ListNode *dummy = new ListNode(-1, head);
            int N = length(head);
            ListNode* s = dummy;
            ListNode* e;
            for (int i = 0; i < N / k; i++) {
                e = s;
                for (int j = 0; j < k; j++)
                    e = e->next;
                s = reverse(s, e, k);
            }
            auto result = dummy->next;
            delete dummy;
            return result;
        }
    
        inline ListNode* reverse(ListNode *start, ListNode *end, int k) {
            auto p1 = start->next;
            auto p2 = end->next;
            ListNode *temp;
            for (int i = 0; i < k; i++) {
                temp = p1->next;
                p1->next = p2;
                p2 = p1;
                p1 = temp;
            }
            auto back = start->next;
            start->next = p2;
            return back;
        }
    
        inline int length(ListNode *node) {
            int N = 0;
            while (node != NULL) {
                node = node->next;
                N++;
            }
            return N;
        }
};

int main(void) {
    Solution s;
}