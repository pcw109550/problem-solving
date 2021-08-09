// 1654. Minimum Jumps to Reach Home
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // O(N)
        int result = -1;
        unordered_set<int> F;
        int Max = INT_MIN;
        for (auto idx : forbidden) {
            F.insert(idx);
            Max = max(Max, idx);
        }
        vector<vector<int> > D (Max + x + b + a, vector<int>(2, -1));
        D[0][0] = 0;
        unordered_set<int> cur {0};
        while (!cur.empty()) {
            unordered_set<int> temp;
            for (auto it : cur) {
                if (it == x) {
                    int result = INT_MAX;
                    result = D[x][0] == -1 ? result : min(result, D[x][0]);
                    result = D[x][1] == -1 ? result : min(result, D[x][1]);
                    return result;
                }
                if (it + a < D.size() && !F.count(it + a) && D[it + a][0] == -1) {
                    int t = INT_MAX;
                    t = D[it][0] == -1 ? t : min(t, D[it][0]);
                    t = D[it][1] == -1 ? t : min(t, D[it][1]);
                    D[it + a][0] = t + 1;
                    temp.insert(it + a);
                }
                if (it - b >= 0 && !F.count(it - b) && D[it - b][1] == -1 && D[it][0] != -1) {
                    D[it - b][1] = D[it][0] + 1;
                    temp.insert(it - b);
                }
            }
            cur = temp;
        }
        return -1;
    }
};

int main(void) {
    Solution s;
}