#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int a, int b) {
        // O(N ** 2)
        int N = nums.size();
        vector<int> D(N + 1);
        for (int i = 0; i < N; i++)
            D[i + 1] = D[i] + nums[i];
        int result = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                int Min = min(i, j);
                int Max = max(i + a - 1, j + b - 1);
                if (Max >= N)
                    continue;
                if (Max - Min + 1 < a + b)
                    continue;
                int A = D[i + a] - D[i];
                int B = D[j + b] - D[j];
                result = max(result, A + B);
            }
        return result;
    }
};