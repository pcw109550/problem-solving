// 1200. Minimum Absolute Difference
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // O(N * log(N))
        vector<vector<int> > result;
        int N = arr.size();
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for (int i = 0; i < N - 1; i++)
            diff = min(diff, abs(arr[i] - arr[i + 1]));
        for (int i = 0; i < N - 1; i++)
            if (abs(arr[i] - arr[i + 1]) == diff)
                result.push_back({arr[i], arr[i + 1]});
        return result;
    }
};

int main(void) {
    Solution s;
}
