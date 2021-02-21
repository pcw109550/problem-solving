// 567. Permutation in String
#include <iostream>
#include <string>

class Solution {
    public:
        bool checkInclusion(std::string s1, std::string s2) {
            // O(N)
            int occ[26] = {}, curr[26] = {};
            for (auto c : s1)
                occ[c - 'a']++;
            for (int i = 0; i < s2.size(); i++) {
                curr[s2[i] - 'a']++;
                if (i >= s1.size())
                    curr[s2[i - s1.size()] - 'a']--;
                bool eq = true;
                for (int j = 0; j < 26; j++)
                    if (occ[j] != curr[j]) {
                        eq = false;
                        break;
                    }
                if (eq)
                    return true;
            }
            return false;
        }
};

int main(void) {
    Solution s;
}