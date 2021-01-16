// 215. Kth Largest Element in an Array
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        int findKthLargest(std::vector<int>& nums, int k) {
            // O(N * log(K))
            std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;
            for (auto num : nums) {
                PQ.push(num);
                if (PQ.size() > k)
                    PQ.pop();
            }
            return PQ.top();
        }
};

int main(void) {
    Solution s;
}