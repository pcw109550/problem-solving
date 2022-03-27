// 789. Escape The Ghosts

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        // O(N)
        int Min = INT_MAX;
        int N = ghosts.size();
        int DX = target[0], DY = target[1];
        for (int i = 0; i < N; i++)
            Min = min(Min, abs(DX - ghosts[i][0]) + abs(DY - ghosts[i][1]));
        int d = abs(DX) + abs(DY);
        return d < Min;
    }
};

int main(void) {
    Solution s;
}
