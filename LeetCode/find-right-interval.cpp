// 436. Find Right Interval
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // O(N * log(N))
        vector<int> result;
        int N = intervals.size();
        vector<vector<int> > temp; // {start, idx}
        vector<int> re;
        for (int i = 0; i < N; i++)
            temp.push_back(vector<int>{intervals[i][0], i});
        sort(temp.begin(), temp.end());
        for (int i = 0; i < N; i++)
            re.push_back(temp[i][0]);
        for (int i = 0; i < N; i++) {
            int si = intervals[i][0];
            int ei = intervals[i][1];
            int idx = lower_bound(re.begin(), re.end(), ei) - re.begin();
            int res = -1;
            if (idx < N && ei <= re[idx])
                res = temp[idx][1];
            result.push_back(res);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}