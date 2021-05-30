// 709. To Lower Case
#include <iostream>
#include <string>

class Solution {
    public:
        std::string toLowerCase(std::string s) {
            // O(N)
            for (int i = 0; i < s.size(); i++)
                if ('A' <= s[i] && s[i] <= 'Z')
                    s[i] += 'a' - 'A';
            return s;
        }
};

int main(void) {
    Solution s;
}