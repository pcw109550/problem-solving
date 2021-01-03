// 43. Multiply Strings
#include <algorithm>
#include <iostream>
#include <string>

class Solution {
    public:
        std::string multiply(std::string num1, std::string num2) {
            // O(M * N)
            int s2 = num2.size();
            std::string result("0"), temp;
            for (int i = 0; i < s2; i++) {
                if (num2[s2 - 1 - i] != '0') {
                    temp = _multiply(num1, num2[s2 - 1 - i] - '0');
                    if (temp != "0")
                        temp = temp + std::string(i, '0');
                    result = add(result, temp);
                    temp.clear();
                }
            }
            return result;
        }
    
        inline std::string _multiply(std::string num1, int c) {
            std::string result;
            int carry = 0;
            int N = num1.size();
            for (int i = 0; i < N; i++) {
                int temp = (num1[N - 1 - i] - '0') * c;
                if (carry > 0)
                    temp += carry;
                carry = temp / 10;
                temp %= 10;
                result.push_back(temp + '0');
            }
            if (carry > 0)
                result.push_back(carry + '0');
            std::reverse(result.begin(), result.end());
            return result;
        }
    
        inline std::string add(std::string num1, std::string num2) {
            int s1 = num1.size();
            int s2 = num2.size();
            int N = std::max(s1, s2);
            std::string result;
            bool carry = false;
            for (int i = 0; i < N; i++) {
                int a = s1 - 1 >= i ? num1[s1 - 1 - i] - '0' : 0;
                int b = s2 - 1 >= i ? num2[s2 - 1 - i] - '0' : 0;
                int temp = a + b;
                if (carry)
                    temp++;
                carry = temp / 10;
                temp %= 10;
                result.push_back('0' + temp);
            }
            if (carry)
                result.push_back('1');
            std::reverse(result.begin(), result.end());
            return result;
        }
};

int main(void) {
    Solution s;
}