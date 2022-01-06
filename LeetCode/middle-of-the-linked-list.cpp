// 876. Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        // O(N)
        auto p1 = head, p2 = head;
        while (true) {
            if (p2->next == NULL)
                break;
            p1 = p1->next;
            p2 = p2->next;
            if (p2->next == NULL)
                break;
            p2 = p2->next;
        }
        return p1;
    }
};

int main(void) {
    Solution s;
}