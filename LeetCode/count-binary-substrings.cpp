// 696. Count Binary Substrings
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        int countBinarySubstrings(std::string s) {
            // O(N)
            int result = 0;
            std::vector<int> temp;
            char state = s[0];
            int prev = 0;
            for (int i = 0; i < s.size(); i++) {
                if (state != s[i]) {
                    temp.push_back(i - prev);
                    state = s[i];
                    prev = i;
                }
            }
            temp.push_back(s.size() - prev);            
            for (int i = 1; i < temp.size(); i++)
                result += std::min(temp[i - 1], temp[i]);
            return result;
        }
};

int main(void) {
    Solution s;
}