// 9. Palindrome Number
#include <iostream>

class Solution {
    public:
        bool isPalindrome(int x) {
            // O(log(N))
            long long X = static_cast<long long>(x), Y = 0;
            while (X > 0) {
                Y *= 10;
                Y += X % 10;
                X /= 10;
            }
            return x == Y;
        }
};

int main(void) {
    Solution s;
    std::cout << s.isPalindrome(123333321);
}