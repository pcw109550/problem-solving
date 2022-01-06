// 382. Linked List Random Node
#include <iostream>
#include <random>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    mt19937 gen;
    uniform_int_distribution<> distrib;
    vector<int> values;
    int N;
public:
    Solution(ListNode* head) {
        // Time O(N) Memory O(N)
        auto it = head;
        while (it != NULL) {
            values.push_back(it->val);
            it = it->next;
        }
        N = values.size();
        distrib = uniform_int_distribution(0, N - 1);
    }
    
    int getRandom() {
        // O(1)
        int idx = distrib(gen);
        return values[idx];
    }
};


class Solution2 {
    mt19937 gen;
    uniform_int_distribution<> distrib;
    vector<int> values;
    int N;
public:
    Solution(ListNode* head) {
        // Time O(N) Memory O(N)
        auto it = head;
        while (it != NULL) {
            values.push_back(it->val);
            it = it->next;
        }
        N = values.size();
        distrib = uniform_int_distribution(0, N - 1);
    }
    
    int getRandom() {
        // O(1)
        int idx = distrib(gen);
        return values[idx];
    }
};

int main(void) {
    Solution *obj;
}