// 125. Valid Palindrome
#include <iostream>
#include <string>
#include <cctype>

class Solution {
    public:
        bool isPalindrome(std::string s) {
            // O(N)
            std::string temp;
            for (auto c : s)
                if (std::isalnum(c))
                    temp.push_back(lower(c));
            for (int i = 0; i < temp.size() / 2; i++)
                if (temp[i] != temp[temp.size() - i - 1])
                    return false;
            return true;
        }
    
        inline char lower(char c) {
            if ('A' <= c && c <= 'Z')
                c = c + ('a' - 'A');
            return c;
        }
};

int main(void) {
    Solution s;
}