#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // O(M * N)
        int result = 0;
        int M = grid.size(), N = grid[0].size();
        unordered_map<int, int> Xs, Ys;
        vector<vector<int> > servers;
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++)
                if (grid[i][j])
                    servers.push_back(vector<int> {i, j});
        for (auto it : servers) {
            int x = it[0], y = it[1];
            Xs[x]++; Ys[y]++;
        }
        for (auto it : servers) {
            int x = it[0], y = it[1];
            if (Xs[x] > 1 || Ys[y] > 1)
                result++;
        }
        return result;
    }
};