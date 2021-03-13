// 1332. Remove Palindromic Subsequences
#include <iostream>
#include <string>
#include <list>

class Solution {
    public:
        int removePalindromeSub(std::string s) {
            // O(N)
            if (s.size() == 0)
                return 0;
            return is_palindrome(s) ? 1 : 2;
        }
    
        inline int is_palindrome(std::string &s) {
            for (int i = 0; i < s.size() / 2; i++)
                if (s[i] != s[s.size() - i - 1])
                    return false;
            return true;
        }
};

int main(void) {
    Solution s;
}