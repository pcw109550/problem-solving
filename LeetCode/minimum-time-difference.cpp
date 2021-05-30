// 539. Minimum Time Difference
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <climits>

class Solution {
    public:
        int findMinDifference(std::vector<std::string>& timePoints) {
            // O(N * log(N))
            int result = INT_MAX;
            std::set<int> S;
            for (auto timePoint: timePoints)
                S.insert(convert(timePoint));
            if (S.size() != timePoints.size())
                return 0;
            int N = S.size();
            auto it = S.begin();
            int prev = *it;
            for (int i = 0; i < N - 1; i++) {
                it++;
                int cur = *it;
                result = std::min(result, cur - prev);
                prev = cur;
            }
            result = std::min(result, *S.begin() + 60 * 24 - prev);
            return result;
        }
    
        int convert(std::string point) {
            int result = 0;
            int m = 10 * (point[3] - '0') + (point[4] - '0');
            int h = 10 * (point[0] - '0') + (point[1] - '0');
            result = h * 60 + m;
            return result;
        }
};

int main(void) {
    Solution s;
}