// 409. Longest Palindrome
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    public:
        int longestPalindrome(std::string s) {
            // O(N)
            std::unordered_map<char, int> M;
            for (auto it : s)
                M[it]++;
            int result = 0;
            bool has_odd = false;
            for (auto it : M) {
                if (it.second % 2 == 0)
                    result += it.second;
                else {
                    result += it.second != 1 ? it.second - 1 : 0;
                    has_odd = true;
                }
            }
            if (has_odd)
                result++;
            return result;
        }
};

int main(void) {
    Solution s;
}