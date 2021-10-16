// 1143. Longest Common Subsequence
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // O(M * N)
        int result = 0;
        int M = text1.size(), N = text2.size();
        vector<vector<int> > D(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0) {
                    if (text1[i] == text2[j])
                        D[i][j]++;
                    else
                        D[i][j] = j >= 1 ? D[i][j - 1] : 0;
                } else {
                    if (text1[i] == text2[j])
                        D[i][j] = (j >= 1 ? D[i - 1][j - 1] : 0) + 1;
                    else {
                        D[i][j] = j >= 1 ? D[i][j - 1] : 0;
                        D[i][j] = max(D[i][j], D[i - 1][j]);
                    }
                }
                result = max(result, D[i][j]);
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}