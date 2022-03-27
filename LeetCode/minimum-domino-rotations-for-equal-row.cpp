// 1007. Minimum Domino Rotations For Equal Row
#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // O(N)
        int result = INT_MAX;
        unordered_map<int, int> M, M2, M3;
        int N = tops.size();
        for (int i = 0; i < N; i++) {
            int top = tops[i], bottom = bottoms[i];
            M2[top]++; M3[bottom]++;
            if (top == bottom)
                M[top]++;
            else {
                M[top]++;
                M[bottom]++;
            }
        }
        for (auto it : M) {
            int cnt = it.second;
            if (cnt == N) {
                result = min(result, min(M2[it.first], N - M2[it.first]));
                result = min(result, min(M3[it.first], N - M3[it.first]));
            }
        }
        if (result == INT_MAX)
            result = -1;
        return result;
    }
};

int main(void) {
    Solution s;
}
