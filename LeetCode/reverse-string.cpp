// 344. Reverse String
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        void reverseString(std::vector<char>& s) {
            // Time O(n) Space O(1)
            for (int i = 0; i < s.size() / 2; i++) {
                char temp = s[i];
                s[i] = s[s.size() - i - 1];
                s[s.size() - i - 1] = temp;
            }
        }
};

class Solution2 {
    public:
        void reverseString(std::vector<char>& s) {
            // Time O(n) Space O(1)
            for (int i = 0; i < s.size() / 2; i++) {
                std::swap(s[i], s[s.size() - i - 1]);
            }
        }
};

int main(void) {
    Solution s;
    std::vector<char> str {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(str);
    for (auto it : str)
        std::cout << it << ' ';
}