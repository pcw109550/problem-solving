// 1417. Reformat The String
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
    public:
        std::string reformat(std::string s) {
            // O(N)
            std::string result;
            std::vector<char> s1, s2;
            int cnt = 0;
            for (auto &c : s) {
                if ('0' <= c && c <= '9')
                    s1.emplace_back(c);
                else
                    s2.emplace_back(c);
            }
            int delta = s1.size() - s2.size();
            if (std::abs(delta) > 1)
                return result;
            if (s1.size() < s2.size())
                std::swap(s1, s2);
            for (int i = 0; i < s2.size(); i++) {
                result += s1[i];
                result += s2[i];
            }
            if (s2.size() < s1.size())
                result += s1[s1.size() - 1];
            return result;
        }
};

int main(void) {
    Solution s;
    std::string inp ("covid2019");
    std::cout << s.reformat(inp);
}