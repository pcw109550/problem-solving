// 1290. Convert Binary Number in a Linked List to Integer
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        int getDecimalValue(ListNode* head) {
            // O(N)
            if (head == NULL)
                return 0;
            int result = 0;
            while (head != NULL) {
                result <<= 1;
                if (head->val)
                    result |= 1;
                head = head->next; 
            }
            return result;
        }
};

int main(void) {
    Solution s;
}