// 347. Top K Frequent Elements
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

class Solution {
    public:
        std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
            // O(N log(K))
            std::unordered_map<int, int> occ;
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > PQ;
            std::vector<int> result;
            int size = 0;
            for (auto num : nums)
                occ[num]++;
            for (auto it : occ) {
                PQ.push({it.second, it.first});
                if (PQ.size() > k)
                    PQ.pop();
            }
            while (size++ < k) {
                result.push_back(PQ.top().second);
                PQ.pop();
            }
            return result;
        }
};

int main(void) {
    Solution s;
}