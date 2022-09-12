#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        // O(N ** 3)
        double result = 0.0;
        int N = points.size();
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                for (int k = j + 1; k < N; k++) {
                    int x0 = points[i][0], y0 = points[i][1];
                    int x1 = points[j][0], y1 = points[j][1];
                    int x2 = points[k][0], y2 = points[k][1];
                    int dx0 = x1 - x0, dy0 = y1 - y0;
                    int dx1 = x2 - x0, dy1 = y2 - y0;
                    double temp = 1.0 / 2 * abs(dx0 * dy1 - dy0 * dx1);
                    result = max(result, temp);
                }
        return result;
    }
};