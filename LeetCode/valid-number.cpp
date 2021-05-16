// 65. Valid Number
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

class Solution {
    public:
        bool isNumber(std::string s) {
            // O(N)
            std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
            auto it = s.find("e");
            std::vector<std::string> tokens;
            if (it != std::string::npos) {
                tokens.push_back(s.substr(0, it));
                tokens.push_back(s.substr(it + 1, s.size() - it - 1));
            } else
                tokens.push_back(s);
            if (tokens.size() == 1)
                return is_decimal(tokens[0]) || is_integer(tokens[0]);
            if (tokens.size() == 2)
                return (is_decimal(tokens[0]) || is_integer(tokens[0])) && is_integer(tokens[1]);
            return true;
        }
    
        bool is_decimal(std::string s) {
            if (s.size() == 0)
                return false;
            if (s.size() == 1)
                return std::isdigit(s[0]);
            int start = s[0] == '+' || s[0] == '-';
            auto it = s.find(".");
            std::vector<std::string> tokens;
            if (it != std::string::npos) {
                tokens.push_back(s.substr(start, it - start));
                tokens.push_back(s.substr(it + 1, s.size() - it - 1));
            } else
                return false;
            if (tokens[0].size() == 0)
                return is_digit_str(tokens[1], false);
            else
                return is_digit_str(tokens[0], false) && is_digit_str(tokens[1]);
            return true;
        }
    
        bool is_digit_str(std::string s, bool allow_empty=true) {
            if (s.size() == 0 && !allow_empty)
                return false;
            for (auto it : s)
                if (!std::isdigit(it))
                    return false;
            return true;
        }
    
        bool is_integer(std::string s) {
            if (s.size() == 0)
                return false;
            if (s.size() == 1)
                return std::isdigit(s[0]);
            int start = s[0] == '+' || s[0] == '-';
            for (int i = start; i < s.size(); i++)
                if (!std::isdigit(s[i]))
                    return false;
            return true;
        }
};

int main(void) {
    Solution s;
}