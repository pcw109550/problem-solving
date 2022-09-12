#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> nextLargerNodes(ListNode* head) {
        // O(N)
        vector<int> result;
        vector<int> D;
        stack<int> S;
        auto it = head;
        while (it != NULL) {
            D.push_back(it->val);
            it = it->next;
        }
        int N = D.size();
        for (int i = N - 1; i >= 0; i--) {
            while (!S.empty() && S.top() <= D[i]) {
                S.pop();
            }
            if (S.empty())
                result.push_back(0);
            else
                result.push_back(S.top());
            S.push(D[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};