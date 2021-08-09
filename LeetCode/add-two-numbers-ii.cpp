// 445. Add Two Numbers II
#include <algorithm>
#include <iostream>
#include <cmath>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // O(N)
        int m = len(l1), n = len(l2);
        if (m < n)
            swap(l1, l2);
        for (int i = 0; i < abs(m - n); i++)
            l2 = new ListNode(0, l2);
        auto result = recurse(l1, l2);
        if (result->val >= 10) {
            result->val %= 10;
            result = new ListNode(1, result);
        }
        return result;
    }
    
    int len(ListNode *l) {
        return 1 + (l->next == NULL ? 0 : len(l->next));
    }
    
    ListNode *recurse(ListNode *l1, ListNode *l2) {
        if (l1->next == NULL && l2->next == NULL)
            return new ListNode(l1->val + l2->val);
        auto it = recurse(l1->next, l2->next);
        int carry = it->val / 10;
        it->val %= 10;
        return new ListNode(l1->val + l2->val + carry, it);
    }
};

int main(void) {
    Solution s;
}