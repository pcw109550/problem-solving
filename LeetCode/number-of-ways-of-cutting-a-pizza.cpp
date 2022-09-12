#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define FIELD 1000000007

class Solution {
    vector<vector<vector<int> > > D;
    vector<vector<int> > T;
public:
    int ways(vector<string>& pizza, int K) {
        // O(M * N * K * (M + N))
        int M = pizza.size(), N = pizza[0].size();
        D = vector<vector<vector<int> > >(M, vector<vector<int> > (N, vector<int>(K, 0)));
        T = vector<vector<int> >(M, vector<int>(N, 0));
        for (int i = M - 1; i >= 0; i--)
            for (int j = N - 1; j >= 0; j--) {
                T[i][j] = 0;
                T[i][j] += (i + 1 < M ? T[i + 1][j] : 0);
                T[i][j] += (j + 1 < N ? T[i][j + 1] : 0);
                T[i][j] -= ((i + 1 < M && j + 1 < N) ? T[i + 1][j + 1] : 0);
                T[i][j] += (pizza[i][j] == 'A');
            }
        for (int k = 0; k < K; k++) 
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    if (k == 0) {
                        D[i][j][0] = (T[i][j] > 0);
                        continue;
                    }
                    D[i][j][k] = 0;
                    for (int x = i + 1; x < M; x++) {
                        int down = T[x][j];
                        int up = T[i][j] - down;
                        if (down <= 0 || up <= 0)
                            continue;
                        D[i][j][k] = (D[i][j][k] + D[x][j][k - 1]) % FIELD;
                    }
                    for (int y = j + 1; y < N; y++) {
                        int left = T[i][y];
                        int right = T[i][j] - left;
                        if (left <= 0 || right <= 0)
                            continue;
                        D[i][j][k] = (D[i][j][k] + D[i][y][k - 1]) % FIELD;
                    }
                }
        return D[0][0][K - 1];
    }
};