// 1510. Stone Game IV
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        // O(N * sqrt(N))
        vector<bool> D(n + 1, false);
        vector<int> sq;
        unordered_set<int> S;
        for (int i = 1; i * i <= n; i++) {
            D[i * i] = true;
            sq.push_back(i * i);
            S.insert(i * i);
        }
        int K = sq.size();
        for (int i = 1; i <= n; i++) {
            if (S.count(i))
                continue;
            for (int k = 0; k < K && i - sq[k] >= 1; k++)
                if (!D[i - sq[k]]) {
                    D[i] = true;
                    break;
                }
            }
        return D[n];
    }
};

int main(void) {
    Solution s;
}
