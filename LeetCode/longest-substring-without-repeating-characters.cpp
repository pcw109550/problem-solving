// 3. Longest Substring Without Repeating Characters
#include <iostream>
#include <string>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            // O(N)
            int result = 0;
            int occ[128];
            std::fill(occ, occ + 128, -1);
            int start = 0, idx = 0;
            while (idx < s.size()) {
                start = std::max(start, occ[s[idx]] + 1);
                result = std::max(result, idx - start + 1);
                occ[s[idx]] = idx; 
                idx++;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}