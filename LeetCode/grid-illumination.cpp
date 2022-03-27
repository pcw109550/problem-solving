// 1001. Grid Illumination
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int dx[9] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
int dy[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        // O(N + M)
        vector<int> result;
        int M = lamps.size(), K = queries.size();
        unordered_map<int, int> L, R, D1, D2;
        unordered_set<long long> S;
        long long N = n;
        for (auto lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            if (S.count(N * y + x))
                continue;
            L[x]++; R[y]++;
            D1[y - x]++; D2[y + x]++;
            S.insert(N * y + x);
        }
        for (auto query : queries) {
            int x = query[0], y = query[1];
            bool illuminated = false;
            illuminated |= L[x];
            illuminated |= R[y];
            illuminated |= D1[y - x];
            illuminated |= D2[y + x];
            result.push_back(illuminated);
            for (int dir = 0; dir < 9; dir++) {
                int X = x + dx[dir], Y = y + dy[dir];
                if (X < 0 || Y < 0 || X >= n || Y >= n)
                    continue;
                if (S.count(N * Y + X)) {
                    L[X]--; R[Y]--;
                    D1[Y - X]--; D2[Y + X]--;
                    S.erase(N * Y + X);
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
