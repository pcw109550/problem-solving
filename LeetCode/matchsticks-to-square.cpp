// 473. Matchsticks to Square
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    bool result;
    long long target;
    int N;
    public:
        bool makesquare(std::vector<int>& matchsticks) {
            // O(N * 2 ** N)
            result = false;
            N = matchsticks.size();
            long long sum = 0;
            for (auto matchstick : matchsticks)
                sum += matchstick;
            if (sum % 4)
                return false;
            target = sum / 4;
            std::vector<bool> visited (N, false);
            backtrack(matchsticks, visited, 0, 0, 0);
            return result;
        }
    
        void backtrack(std::vector<int> &matchsticks, std::vector<bool> &visited, int cnt, long long acc, int start) {
            if (cnt == 4 || result) {
                result = true;
                return;
            }
            for (int i = start; i < N; i++) {
                if (!visited[i] && acc + matchsticks[i] <= target) {
                    visited[i] = true;
                    if (acc + matchsticks[i] == target)
                        backtrack(matchsticks, visited, cnt + 1, 0, 0);  // start with zero is important 
                    else
                        backtrack(matchsticks, visited, cnt, acc + matchsticks[i], i + 1);
                    visited[i] = false;
                }
            }
        }
};

int main(void) {
    Solution s;
}