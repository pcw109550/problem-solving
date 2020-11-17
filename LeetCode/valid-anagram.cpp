// 242. Valid Anagram
#include <iostream>
#include <string>

class Solution {
    public:
        bool isAnagram(std::string s, std::string t) {
            // O(N)
            if (s.size() != t.size())
                return false;
            int occur[26] = {};
            for (auto &c: s)
                occur[c - 'a']++;
            for (auto &c: t) {
                occur[c - 'a']--;
                if (occur[c - 'a'] < 0)
                    return false;
            }
            return true;
        }
};

int main(void) {
    Solution s;
    std::string a ("anagram"), b ("nagaram");
    std::cout << s.isAnagram(a, b);
}