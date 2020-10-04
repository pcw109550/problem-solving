// 1288. Remove Covered Intervals
#include <iostream>
#include <vector>

class Solution {
    public:
        int removeCoveredIntervals(std::vector<std::vector<int> >& intervals) {
            // O(N ** 2)
            int result = intervals.size();
            int N = result, a, b, c, d;
            for (int i = 0; i < N; i++) {
                a = intervals[i][0];
                b = intervals[i][1];
                for (int j = 0; j < N; j++) {
                    if (i == j)
                        continue;
                    c = intervals[j][0];
                    d = intervals[j][1];
                    if (c <= a && b <= d) {
                        result--;
                        break;
                    }
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<std::vector<int> > intervals {{1, 2}, {1, 4}, {3, 4}};
    int result = s.removeCoveredIntervals(intervals);
    std::cout << result;
}