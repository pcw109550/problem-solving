// 452. Minimum Number of Arrows to Burst Balloons
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            // O(N * log(N))
            int result = 0;
            int N = points.size();
            vector<pair<int, int> > temp;
            for (auto point : points)
                temp.push_back({point[1], point[0]});
            sort(temp.begin(), temp.end());
            int probe = 0;
            while (probe < N) {
                int start = temp[probe].second;
                int end = temp[probe].first;
                int idx = probe + 1; 
                while (idx < N) {
                    int s = temp[idx].second;
                    if (s <= end)
                        idx++;
                    else
                        break;
                }
                result++;
                probe = idx;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}