#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // O(N * log(N))
        int N = dist.size();
        int result = 0;
        vector<double> T;
        for (int i = 0; i < N; i++)
            T.push_back(static_cast<double>(dist[i]) / speed[i]);
        sort(T.begin(), T.end());
        for (int t = 0; t < N; t++) {
            if (t < T[t])
                result++;
            else
                break;
        }
        return result;
    }
};