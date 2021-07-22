// 639. Decode Ways II
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int numDecodings(string s) {
        // O(N)
        long long result = 0;
        int N = s.size();
        vector<vector<long long> > D (N, vector<long long> (10, 0));
        vector<long long> sums(N, 0);
        for (int i = 0; i < N; i++) {
            long long prev1 = i >= 1 ? sums[i - 1] : 0;
            long long prev2 = i >= 2 ? sums[i - 2] : 0;
            if (s[i] != '0') {
                if (s[i] != '*')
                    D[i][s[i] - '0'] += prev1 > 0 ? prev1 : 1;
                else
                    for (int j = 1; j < 10; j++)
                        D[i][j] += prev1 > 0 ? prev1 : 1;
            }
            if (i >= 1 && s[i - 1] != '0') {
                if (s[i] != '*') {
                    if (s[i - 1] == '*')
                         D[i][s[i] - '0'] += (1 + (s[i] - '0' <= 6)) * (prev2 > 0 ? prev2 : 1);
                    else {
                        int cand = (s[i - 1] - '0') * 10 + s[i] - '0';
                        if (1 <= cand && cand <= 26)
                            D[i][s[i] - '0'] += prev2 > 0 ? prev2 : 1;
                    }
                } else {
                    if (s[i - 1] == '*')
                        for (int j = 1; j < 10; j++)
                            D[i][j] += (1 + (j <= 6)) * (prev2 > 0 ? prev2 : 1);
                    else if (s[i - 1] == '1')
                        for (int j = 1; j < 10; j++)
                            D[i][j] += prev2 > 0 ? prev2 : 1;
                    else if (s[i - 1] == '2')
                        for (int j = 1; j <= 6; j++)
                            D[i][j] += prev2 > 0 ? prev2 : 1;
                }
            }
            for (int j = 0; j < 10; j++) {
                D[i][j] %= FIELD;
                sums[i] += D[i][j];
            }
            sums[i] %= FIELD;
            if (sums[i] == 0)
                return 0;
        }
        result = sums[N - 1];
        return result;
    }
};

int main(void) {
    Solution s;
}