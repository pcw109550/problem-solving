#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // O(N ** 2)
        int N = arr.size();
        int result = 0;
        vector<vector<int> > M(N + 1, vector<int>(N + 1));
        unordered_map<int, int> idxs;
        for (int i = 1; i <= N; i++)
            idxs[arr[i - 1]] = i;
        for (int i = 1; i < N; i++) {
            int b = arr[i];
            for (int j = 0; j < i; j++) {
                int a = arr[j];
                // target: {b - a, a} <- {a, b}
                auto it = lower_bound(arr.begin(), arr.end(), b - a);
                int idx = *it == b - a ? it - arr.begin() + 1 : 0;
                int temp = M[j + 1][i + 1] = M[idx][j + 1] + 1;
                result = max(result, temp);
            }
        }
        return result < 2 ? 0 : result + 1;
    }
};