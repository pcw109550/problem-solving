// 633. Sum of Square Numbers
#include <iostream>
#include <unordered_set>

class Solution {
    public:
        bool judgeSquareSum(int c) {
            // O(sqrt(c))
            std::unordered_set<int> cands;
            for (long long i = 0; i * i <= c; i++)
                cands.insert(i * i);
            for (auto cand : cands)
                if (cands.count(c - cand))
                    return true;
            return false;
        }
};

int main(void) {
    Solution s;
}