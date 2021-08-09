// 435. Non-overlapping Intervals
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // O(N * log(N))
        int N = intervals.size();
        vector<pair<int, int> > input;
        int result = 0;
        for (auto it : intervals)
            input.push_back({it[1], it[0]});
        sort(input.begin(), input.end());
        int cur = 0;
        int probe = 1;
        while (probe < N) {
            int cur_e = input[cur].first;
            int cur_s = input[cur].second;
            int pro_e = input[probe].first;
            int pro_s = input[probe].second;
            if (cur_e <= pro_s)
                cur = probe;
            else
                result++;
            probe++;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}