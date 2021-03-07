// 1781. Sum of Beauty of All Substrings
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

class Solution {
    int result;
    int N;
    public:
        int beautySum(std::string s) {
            // O(c * N ** 2)
            result = 0;
            N = s.size();
            for (int i = 0; i < N; i++)
                beauty(s, i);
            return result;
        }
    
        inline void beauty(std::string &s, int start) {
            auto cur = s.substr(start, N - start);
            std::unordered_map<char, int> M;
            for (auto c : cur) {
                M[c]++;
                int Max = INT_MIN, Min = INT_MAX;
                for (auto it : M) {
                    Max = std::max(Max, it.second);
                    Min = std::min(Min, it.second);
                }
                result += Max - Min;
            }
        }
};

int main(void) {
    Solution s;
}