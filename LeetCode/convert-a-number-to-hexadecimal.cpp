// 405. Convert a Number to Hexadecimal
#include <iostream>
#include <string>

class Solution {
    char table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                            'a', 'b', 'c', 'd', 'e', 'f'};
    public:
        std::string toHex(int num) {
            // O(log N)
            if (num == 0)
                return std::string ("0");
            std::string result ("");
            unsigned int target = static_cast<unsigned int>(num);
            while (target > 0) {
                result = std::string (1, table[target % 16]) + result;
                target /= 16;
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::string result = s.toHex(0);
    std::cout << result;
}
