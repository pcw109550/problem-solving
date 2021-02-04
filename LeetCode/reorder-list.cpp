// 143. Reorder List
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
        void reorderList(ListNode* head) {
            // O(N)
            std::vector<ListNode *> nodes;
            auto node = head;
            while (node != NULL) {
                nodes.push_back(node);
                node = node->next;
            }
            node = head;
            int N = nodes.size(), x = 1, y = N - 1, acc = 1;
            while (acc < N) {
                if (acc % 2) {
                    node->next = nodes[y--];
                } else {
                    node->next = nodes[x++];
                }
                node = node->next;
                acc++;
            }
            if (node != NULL)
                node->next = NULL;
        }
};

int main(void) {
    Solution s;
}