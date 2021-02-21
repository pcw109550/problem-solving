// 49. Group Anagrams
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
    public:
        std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
            // O(N * M * log (M))
            std::unordered_map<std::string, std::vector<std::string> > M;
            std::vector<std::vector<std::string> > result;
            for (auto str : strs) {
                auto temp = str;
                std::sort(temp.begin(), temp.end());
                M[temp].push_back(str);
            }
            for (auto it : M)
                result.push_back(it.second);
            return result;
        }
};

int main(void) {
    Solution s;
}