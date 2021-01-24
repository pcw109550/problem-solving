// 403. Frog Jump
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
    public:
        bool canCross(std::vector<int>& stones) {
            // O(N ** 2)
            std::unordered_map<int, std::unordered_set<int>> steps = {{0, {0}}};  
            for (auto pos : stones) {
                for (auto it = steps[pos].begin(); it != steps[pos].end(); it++) { 
                    if (*it - 1)
                        steps[pos + *it - 1].insert(*it - 1);
                    steps[pos + *it].insert(*it);
                    steps[pos + *it + 1].insert(*it + 1);
                }
            }
            return !steps[stones.back()].empty();
    }
};

class Solution2 {
    public:
        bool canCross(std::vector<int>& stones) {
            // O(N ** 3)
            int N = stones.size();
            if (stones[1] != 1)
                return false;
            std::vector<std::unordered_set<int> > D (N, std::unordered_set<int> ());
            D[1].insert(0);
            for (int i = 2; i < N; i++) {
                for (int j = 0; j < i; j++) {
                    int dist = stones[i] - stones[j];
                    for (auto it : D[j]) {
                        if (dist == stones[j] - it + 1)
                            D[i].insert(stones[j]);
                        else if (dist == stones[j] - it)
                            D[i].insert(stones[j]);
                        else if (dist == stones[j] - it - 1)
                            D[i].insert(stones[j]);
                    }
                }
            }
            return D[N - 1].size() > 0;
        }
};

int main(void) {
    Solution s;
}