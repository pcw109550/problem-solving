#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // O(N)c
        vector<vector<int> > result;
        int A = newInterval[0], B = newInterval[1];
        int N = intervals.size();
        intervals.push_back(vector<int> {200000, 200001});
        bool inserted = false;
        if (B < intervals[0][0]) {
            inserted = true;
            result.push_back(newInterval);
        }
        int nA = 200000, nB = -1;
        for (int i = 0; i < N; i++) {
            if (inserted) {
                result.push_back(intervals[i]);
                continue;
            }
            int ac = intervals[i][0], bc = intervals[i][1];
            int an = intervals[i + 1][0], bn = intervals[i + 1][1];
            if (bc < A && B < an) {
                result.push_back(intervals[i]);
                result.push_back(newInterval);
                inserted = true;
                continue;
            }
            int L = min(ac, A), R = max(bc, B);
            if (B - A + bc - ac < R - L) {
                if (nB != -1) {
                    inserted = true;
                    result.push_back(vector<int> {nA, nB});
                }
                result.push_back(intervals[i]);
                continue;
            }
            // overlapped
            nA = min(nA, min(ac, A)), nB = max(nB, max(bc, B));
        }
        if (!inserted && nB != -1)
            result.push_back(vector<int>{nA, nB});
        return result;
    }
};