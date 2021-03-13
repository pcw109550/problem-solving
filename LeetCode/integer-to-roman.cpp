// 12. Integer to Roman
#include <iostream>
#include <string>

class Solution {
    public:
        std::string intToRoman(int num) {
            // O(1)
            std::string result;
            int digit[4] = {};
            for (int i = 0; i < 4; i++) {
                digit[i] = num % 10;
                num /= 10;
            }
            result += std::string(digit[3], 'M');
            helper(result, digit[2], 'C', 'D', 'M');
            helper(result, digit[1], 'X', 'L', 'C');
            helper(result, digit[0], 'I', 'V', 'X');
            return result;
        }
    
        void helper(std::string &result, int digit, char c, char d, char e) {
            switch (digit) {
                case 4:
                    result += std::string(1, c) + std::string(1, d);
                    break;
                case 9:
                    result += std::string(1, c) + std::string(1, e);
                    break;
                default:
                    if (digit >= 5)
                        result += std::string(1, d);
                    result += std::string(digit % 5, c);
                    break;
            }
        }
};

int main(void) {
    Solution s;
}