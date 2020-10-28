// 5. Longest Palindromic Substring
#include <iostream>
#include <string>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            // Time O(N ** 2) Space O(1)
            int N = s.length();
            if (N == 0)
                return std::string ("");
            int start = 0, end = 0;
            for (int i = 0; i < N; i++) {
                int len1 = expand(s, i, i);
                int len2 = expand(s, i, i + 1);
                int len = std::max(len1, len2);
                if (len > end - start) {
                    start = i - (len - 1) / 2;
                    end = i + len / 2;
                }                
            }
            return s.substr(start, end - start + 1);
        }

        int expand(std::string s, int left, int right) {
            int L = left, R = right;
            int N = s.length();
            while (L >= 0 && R < N && s[L] == s[R]) {
                L--; R++;
            }
            return R - L - 1;
        }
};

class Solution2 {
    public:
        std::string longestPalindrome(std::string s) {
            // Time O(N ** 2) Space O(N ** 2)
            int N = s.length(), Max = 1, idx = 0;
            if (N == 0)
                return std::string ("");
            bool is_palindrome[1000][1000];
            std::fill(is_palindrome[0], is_palindrome[0] + 1000 * 1000, false);
            for (int i = 1; i <= N; i++) {
                for (int j = 0; j <= N - i; j++) {
                    if (i == 1) {
                        is_palindrome[j][j] = true;
                    } else {
                        if (s[j] != s[j + i - 1])
                            continue;
                        if (i == 2 || is_palindrome[j + 1][j + i - 2]) {
                            is_palindrome[j][j + i - 1] = true;
                            idx = j; Max = i;
                        }
                    }
                }
            }
            return s.substr(idx, Max);
        }
};

int main(void) {
    Solution s;
    std::string input = "babad";
    auto result = s.longestPalindrome(input);
    std::cout << result;
}