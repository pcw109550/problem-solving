// 1876. Substrings of Size Three with Distinct Characters
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
    public:
        int countGoodSubstrings(std::string s) {
            // O(N)
            int N = s.size();
            int result = 0;
            for (int i = 0; i <= N - 3; i++) {
                std::unordered_set<char> S;
                for (int j = i; j < i + 3; j++)
                    S.insert(s[j]);
                if (S.size() == 3)
                    result++;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}