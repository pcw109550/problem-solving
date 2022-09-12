#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        // O(N * log(N))
        long long N = beans.size();
        long long sum = accumulate(beans.begin(), beans.end(), 0L);
        sort(beans.begin(), beans.end());
        long long result = LLONG_MAX;
        for (long long i = 0; i < N; i++) {
            long long cur = sum - (long long)beans[i] * (N - i);
            result = min(result, cur);
        }
        return result;
    }
};