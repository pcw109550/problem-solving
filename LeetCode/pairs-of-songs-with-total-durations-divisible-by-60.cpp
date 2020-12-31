// 1010. Pairs of Songs With Total Durations Divisible by 60

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int numPairsDivisibleBy60(std::vector<int>& time) {
            // O(N)
            std::unordered_map<int, int> M;
            int result = 0;
            for (auto it : time) {
                int temp = it % 60;
                if (M.find((60 - temp) % 60) != M.end())
                    result += M[(60 - temp) % 60];
                if (M.find(temp) == M.end())
                    M[temp] = 1;
                else
                    M[temp]++;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}