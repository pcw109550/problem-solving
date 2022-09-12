#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // O(N ** 2)
        int N = s.size();
        int result_idx = 0, result_max = 0;
        vector<vector<bool> > D(N, vector<bool> (N, false));
        for (int x = N - 1; x >= 0; x--) {
            for (int y = 0; y <= x; y++) {
                int i = y;
                int j = y + N - 1 - x;
                bool is_palin = false;
                if (s[i] == s[j]) {
                    if (i == j || i + 1 == j || D[i + 1][j - 1]) {
                        D[i][j] = true;
                        int delta = j - i + 1;
                        if (result_max < delta) {
                            result_max = delta;
                            result_idx = i;
                        }
                    }
                }
            }
        }
        string result = s.substr(result_idx, result_max);
        return result; 
    }
};