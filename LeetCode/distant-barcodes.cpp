// 1054. Distant Barcodes
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

class Solution {
    public:
        std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes) {
            // O(N log(K))
            std::vector<int> result;
            std::unordered_map<int, int> M;
            int total = 0;
            for (auto &barcode : barcodes) {
                M[barcode]++;
                total++;
            }
            std::priority_queue<std::pair<int, int> > PQ; // {count, type}
            for (auto it : M)
                PQ.push({it.second, it.first});
            std::pair<int, int> prev {-1, -1}; // dummy
            while (total--) {
                auto next = PQ.top(); PQ.pop();
                PQ.push(prev);
                prev = next;
                result.push_back(prev.second);
                prev.first--;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}