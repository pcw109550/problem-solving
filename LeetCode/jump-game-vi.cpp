// 1696. Jump Game VI
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <set>

class Solution {
    public:
        int maxResult(std::vector<int>& nums, int k) {
            // O(N * log(K))
            int next;
            std::multiset<int, std::greater<int> > M;
            std::deque<int> Q;
            for (auto &num : nums) {
                next = (M.empty() ? 0 : *M.begin()) + num;
                if (M.size() == k) {
                    M.erase(M.lower_bound(Q.front()));
                    Q.pop_front();
                }
                M.insert(next);
                Q.push_back(next);
            }
            return Q.back();
        }
};

int main(void) {
    Solution s;
}