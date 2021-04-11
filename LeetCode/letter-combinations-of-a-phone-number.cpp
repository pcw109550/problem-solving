// 17. Letter Combinations of a Phone Number
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    public:
        std::vector<std::string> letterCombinations(std::string digits) {
            // O(N * 4 ** N)
            std::unordered_map<char, std::vector<char> > M;
            M['2'] = std::vector<char> {'a', 'b', 'c'};
            M['3'] = std::vector<char> {'d', 'e', 'f'};
            M['4'] = std::vector<char> {'g', 'h', 'i'};
            M['5'] = std::vector<char> {'j', 'k', 'l'};
            M['6'] = std::vector<char> {'m', 'n', 'o'};
            M['7'] = std::vector<char> {'p', 'q', 'r', 's'};
            M['8'] = std::vector<char> {'t', 'u', 'v'};
            M['9'] = std::vector<char> {'w', 'x', 'y', 'z'};
            
            std::vector<std::string> result;
            for (auto digit: digits) {
                std::vector<std::string> temp;
                for (auto c: M[digit]) {
                    if (result.empty())
                        temp.push_back(std::string (1, c));
                    else {
                        for (auto str: result)
                            temp.push_back(str + c);
                    }
                }
                result = temp;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}