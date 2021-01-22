// 1347. Minimum Number of Steps to Make Two Strings Anagram
#include <cmath>
#include <iostream>
#include <string>

class Solution {
    public:
        int minSteps(std::string s, std::string t) {
            // O(N)
            int result = 0;
            int o1[26] = {}, o2[26] = {};
            for (auto it : s)
                o1[it - 'a']++;
            for (auto it : t)
                o2[it - 'a']++;
            for (int i = 0; i < 26; i++)
                result += std::abs(o1[i] - o2[i]);
            result /= 2;
            return result;
        }
};

int main(void) {
    Solution s;
}