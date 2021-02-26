// 1503. Last Moment Before All Ants Fall Out of a Plank
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
            // O(N)
            int Max = INT_MIN, Min = INT_MAX;
            for (auto it : left)
                Max = std::max(Max, it);
            for (auto it : right)
                Min = std::min(Min, it);
            if (Max == INT_MIN)
                return n - Min;
            if (Min == INT_MAX)
                return Max;
            return std::max(n - Min, Max);
        }
};

int main(void) {
    Solution s;
}