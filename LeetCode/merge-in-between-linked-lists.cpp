#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // O(N + M)
        ListNode *dummy = new ListNode(-1);
        auto cur = dummy;
        auto it = list1;
        int cnt = 0;
        bool added = false;
        while (it) {
            if (cnt < a || cnt > b) {
                cur->next = new ListNode(it->val);
                cur = cur->next;
            } else {
                if (!added) {
                    added = true;
                    auto it2 = list2;
                    while (it2) {
                        cur->next = new ListNode(it2->val);
                        cur = cur->next;
                        it2 = it2->next;
                    }
                }
            }
            cnt++;
            it = it->next;
        }
        auto result = dummy->next;
        delete dummy;
        return result;
    }
};