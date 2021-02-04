// 1370. Increasing Decreasing String
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::string sortString(std::string s) {
            // O(N)
            std::string result; // push_back
            int occ[26] = {};
            int total = 0;
            for (auto c : s) {
                occ[c - 'a']++;
                total++;
            }
            while (total) {
                for (int i = 0; i < 26 && total; i++) {
                    if (occ[i]) {
                        result.push_back('a' + i);
                        occ[i]--; total--;
                    }
                }
                for (int i = 25; i >= 0 && total; i--) {
                    if (occ[i]) {
                        result.push_back('a' + i);
                        occ[i]--; total--;
                    }
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}