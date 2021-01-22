// 1657. Determine if Two Strings Are Close
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    public:
        bool closeStrings(std::string word1, std::string word2) {
            // O(N)
            if (word1.size() != word2.size())
                return false;
            std::unordered_map<char, int> M1, M2;
            std::vector<int> c1, c2;
            std::vector<char> o1, o2;
            for (auto c : word1)
                M1[c]++;
            for (auto c : word2)
                M2[c]++;
            for (auto it : M1) {
                o1.push_back(it.first);
                c1.push_back(it.second);
            }
            for (auto it : M2) {
                o2.push_back(it.first);
                c2.push_back(it.second);
            }
            std::sort(c1.begin(), c1.end());
            std::sort(c2.begin(), c2.end());
            std::sort(o1.begin(), o1.end());
            std::sort(o2.begin(), o2.end());
            return c1 == c2 && o1 == o2;
        }
};

int main(void) {
    Solution s;
}