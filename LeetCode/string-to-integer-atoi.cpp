// 8. String to Integer (atoi)
#include <algorithm>
#include <iostream>
#include <string>

#define INT_MAX  2147483647
#define INT_MIN -2147483648

class Solution {
    public:
        int myAtoi(std::string str) {
            // O(n)
            int result = 0, next_result = 0;
            bool neg = false;
            auto it = str.begin();
            while (*it == ' ')
                it++;
            if (it == str.end())
                return 0;
            if (!std::isdigit(*it))
                if (*it == '-') {
                    neg = true;
                    it++;
                } else if (*it == '+') {
                    it++;
                } else 
                    return 0;
            while (it != str.end()) {
                if (!std::isdigit(*it))
                    return result;
                int current = *it - '0';
                // Custom overflow detection
                if (neg) {
                    if (next_result < INT_MIN / 10)
                        return INT_MIN;
                } else {
                    if (next_result > INT_MAX / 10)
                        return INT_MAX;
                }
                next_result = 10 * result;
                if (neg) {
                    if (next_result < INT_MIN + current)
                        return INT_MIN;
                } else {
                    if (next_result > INT_MAX - current)
                        return INT_MAX;
                }
                next_result += current * (neg ? -1 : 1);
                result = next_result;
                it++;
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::string str("+1000");
    int result = s.myAtoi(str);
    std::cout << result << std::endl;
}