// 537. Complex Number Multiplication
#include <iostream>
#include <string>
#include <utility>

class Solution {
    public:
        std::string complexNumberMultiply(std::string x, std::string y) {
            // O(1)
            std::string result;
            auto A = parse(x), B = parse(y);
            int a = A.first, b = A.second;
            int c = B.first, d = B.second;
            result += std::to_string(a * c - b * d) + "+" + std::to_string(a * d + b * c) + "i";
            return result;
        }
    
        std::pair<int, int> parse(std::string &s) {
            int idx = s.find("+");
            return {std::stoi(s.substr(0, idx)), std::stoi(s.substr(idx + 1, s.size() - idx - 2))};
        }
};

int main(void) {
    Solution s;
}