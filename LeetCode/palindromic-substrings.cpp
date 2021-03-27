// 647. Palindromic Substrings
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        int countSubstrings(std::string s) {
            // O(N ** 2)
            int result = 0;
            int N = s.size();
            std::vector<std::vector<bool> > D (N, std::vector<bool> (N, 0));
            for (int l = 0; l < N; l++)
                for (int i = 0; i < N - l; i++) {
                    if (s[i] == s[i + l] ) {
                        if (l > 1 && !D[i + 1][i + l - 1])
                            continue;
                        D[i][i + l] = true;
                        result++;
                    }
                }
            return result;
        }
};

int main(void) {
    Solution s;
}