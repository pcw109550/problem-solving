// 516. Longest Palindromic Subsequence

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        int longestPalindromeSubseq(std::string s) {
            // O(N ** 2)
            int N = s.size();
            std::vector<std::vector<int> > D(N + 1, std::vector<int> (N));
            for (int i = 0; i < N; i++)
                D[1][i] = 1;
            for (int i = 2; i <= N; i++) // length
                for (int j = 0; j < N - i + 1; j++) { // start index 
                    if (s[j] == s[i + j - 1])
                        D[i][j] = D[i - 2][j + 1] + 2;
                    else 
                        D[i][j] = std::max(D[i - 1][j], D[i - 1][j + 1]);
                }
            return D[N][0]; 
        }
};

int main(void) {
    Solution s;
}