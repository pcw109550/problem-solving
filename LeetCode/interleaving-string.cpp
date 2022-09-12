#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // O(M * N)
        int M = s1.size(), N = s2.size(), K = s3.size();
        if (M + N < K || M + N > K)
            return false;
        vector<vector<bool> > D(M + 1, vector<bool>(N + 1, false));
        D[0][0] = true;
        for (int i = 1; i <= K; i++) {
            for (int j = 0; j <= i; j++) {
                int x = j, y = i - j;
                if (x < 0 || x > M || y < 0 || y > N)
                    continue;
                bool a = x >= 1 ? D[x - 1][y] : false;
                bool b = y >= 1 ? D[x][y - 1] : false;
                D[x][y] = (a && (s1[x - 1] == s3[x + y - 1])) || (b && (s2[y - 1] == s3[x + y - 1]));
            }
        }
        return D[M][N];
    }
};