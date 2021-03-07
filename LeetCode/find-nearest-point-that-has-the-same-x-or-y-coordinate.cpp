// 1779. Find Nearest Point That Has the Same X or Y Coordinate
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int nearestValidPoint(int x, int y, std::vector<std::vector<int> >& points) {
            // O(N)
            int min_dist = INT_MAX;
            int result = -1;
            for (int i = 0; i < points.size(); i++) {
                if (x == points[i][0] || y == points[i][1]) {
                    int dist = std::abs(x - points[i][0]) + std::abs(y - points[i][1]);
                    if (min_dist > dist) {
                        min_dist = dist;
                        result = i;
                    }
                }
            }
            return result;
    }
};

int main(void) {
    Solution s;
}
