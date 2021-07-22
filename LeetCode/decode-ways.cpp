// 91. Decode Ways
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            // O(N)
            int result = 0;
            int N = s.size();
            vector<int> D (N, 0);
            for (int i = 0; i < N; i++) {
                if (s[i] != '0')
                    D[i] += i >= 1 ? D[i - 1] : 1;
                if (i >= 1 && s[i - 1] != '0') {
                    int cand = (s[i - 1] - '0') * 10 + s[i] - '0';
                    if (1 <= cand && cand <= 26 )
                        D[i] += i >= 2 ? D[i - 2] : 1;
                }
            }
            result = D[N - 1];
            return result;
        }
};

int main(void) {
    Solution s;
}