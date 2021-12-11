// 986. Interval List Intersections
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // O(N)
        vector<vector<int> > result;
        int L1 = firstList.size();
        int L2 = secondList.size();
        int probe = 0;
        for (int i = 0; i < L1 && probe < L2; i++) {
            int cur_start = firstList[i][0];
            int cur_end = firstList[i][1];
            while (probe < L2) {
                if (secondList[probe][1] < cur_start)
                    probe++;
                else {
                    int L = max(secondList[probe][0], cur_start);
                    int R = min(secondList[probe][1], cur_end);
                    if (L <= R)
                        result.push_back(vector<int>{L, R});
                    if (secondList[probe][1] <= cur_end)
                        probe++;
                    else
                        break;
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}