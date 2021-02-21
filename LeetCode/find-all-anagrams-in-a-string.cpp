// 438. Find All Anagrams in a String
#include <iostream>
#include <vector>
#include <string>

class Solution {
    public:
        std::vector<int> findAnagrams(std::string s, std::string p) {
            // O(N)
            std::vector<int> result;
            int cnt[26] = {};
            int target[26] = {};
            for (auto c : p)
                target[c - 'a']++;
            for (int i = 0; i < s.size(); i++) {
                cnt[s[i] - 'a']++;
                if (i >= p.size()) {
                    cnt[s[i - p.size()] - 'a']--;
                }
                bool add = true;
                for (int j = 0; j < 26; j++)
                    if (cnt[j] != target[j]) {
                        add = false;
                        break;
                    }
                if (add)
                    result.push_back(i - p.size() + 1);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}