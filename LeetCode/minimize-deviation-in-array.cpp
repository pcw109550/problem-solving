// 1675. Minimize Deviation in Array
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#define MAX 1 << 30

class Solution {
    public:
        int minimumDeviation(std::vector<int>& nums) {
            // O(N * log(N) * log(M))
            int res = MAX, min_n = MAX;
            std::priority_queue<int> PQ;
            for (auto n : nums) {
                n = n % 2 ? n * 2 : n;
                PQ.push(n);
                min_n = std::min(min_n, n); 
            }
            while (PQ.top() % 2 == 0) {
                res = std::min(res, PQ.top() - min_n);
                min_n = std::min(min_n, PQ.top() / 2);
                PQ.push(PQ.top() / 2);
                PQ.pop();
            }
            return std::min(res, PQ.top() - min_n);
        }
};

int main(void) {
    Solution s;
}