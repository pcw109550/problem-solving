// 692. Top K Frequent Words
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <string>

class Solution {
    public:
        std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
            // O(N log(K))
            std::unordered_map<std::string, int> occ;
            auto cmp = [=](std::pair<int, std::string> &A, std::pair<int, std::string> &B) {
                if (A.first == B.first)
                    return A.second < B.second;
                return A.first > B.first;
            };
            std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string> >, decltype(cmp) > PQ(cmp);
            std::vector<std::string> result;
            for (auto word : words)
                occ[word]++;
            for (auto it : occ) {
                PQ.push({it.second, it.first});
                if (PQ.size() > k)
                    PQ.pop();
            }
            while (!PQ.empty()) {
                result.push_back(PQ.top().second);
                PQ.pop();
            }
            std::reverse(result.begin(), result.end());
            return result;
        }
};

int main(void) {
    Solution s;
}