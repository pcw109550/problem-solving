// 115. Distinct Subsequences
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // O(N ** 2)
        int result = 0;
        int S = s.size(), T = t.size();
        vector<vector<long long> > D (S, vector<long long>(T, 0));
        vector<long long> cache(T, 0);
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < T; j++) {
                if (s[i] != t[j])
                    continue;
                if (j == 0) {
                    D[i][j] = 1;
                } else {
                    if (i >= 1)
                        D[i][j] = cache[j - 1];
                }
            }
            if (i >= 0)
                for (int j = 0; j < T; j++) {
                    // Shitty overflow hack :C
                    if (cache[j] > (1L << 61))
                        break;
                    cache[j] += D[i][j];
                }
        }
        
        result = cache[T - 1];
        return result;
    }
};

class Solution2 {
public:
    int numDistinct(string s, string t) {
        // O(N ** 3)
        int result = 0;
        int S = s.size(), T = t.size();
        vector<vector<long long> > D (S, vector<long long>(T, 0));
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < T; j++) {
                if (s[i] != t[j])
                    continue;
                if (j == 0) {
                    D[i][j] = 1;
                } else {
                    for (int k = 0; k < i; k++) {
                        D[i][j] += D[k][j - 1];
                        if (D[i][j] > INT_MAX)
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < S; i++)
            result += D[i][T - 1];
        return result;
    }
};

int main(void) {
    Solution s;
}