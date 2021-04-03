// 423. Reconstruct Original Digits from English
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
    std::vector<int> _result;
    std::unordered_map<char, int> M;
    public:
        std::string originalDigits(std::string s) {
            // O(N)
            std::string result;
            for (auto c : s)
                M[c]++;
            task(0, "zero", 'z');
            task(2, "two", 'w');
            task(4, "four", 'u');
            task(6, "six", 'x');
            task(1, "one", 'o');
            task(7, "seven", 's');
            task(5, "five", 'v');
            task(8, "eight", 'g');
            task(9, "nine", 'i');
            task(3, "three", 't');
            std::sort(_result.begin(), _result.end());
            for (auto it : _result)
                result.push_back(it + '0');
            return result;
        }
    
        void task(int digit, std::string s, char target) {
            if (M.count(target)) {
                int cnt = M[target];
                for (int i = 0; i < cnt; i++)
                    _result.push_back(digit);
                M.erase(target);
                for (auto c : s)
                    if (c != target) {
                        M[c] -= cnt;
                        if (M[c] == 0)
                            M.erase(c);
                    }
            }
        }
};

int main(void) {
    Solution s;
}