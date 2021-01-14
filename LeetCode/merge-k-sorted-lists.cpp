// 23. Merge k Sorted Lists
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
        ListNode *mergeKLists(std::vector<ListNode *>& lists) {
            // O(N)
            ListNode *result = NULL, *current;
            current = result;
            short cnt[20001] = {};
            for (auto node : lists)
                while (node != NULL) {
                    cnt[node->val + 10000]++;
                    node = node->next;
                }
            
            for (int i = 0; i <= 20000; i++) {
                while (cnt[i] > 0) {
                    if (result == NULL) {
                        result = new ListNode(i - 10000);
                        current = result;
                    } else {
                        current->next = new ListNode(i - 10000);
                        current = current->next;
                    }   
                    cnt[i]--;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}