// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
#include <algorithm>
#include <iostream>
#include <vector>
#define FIELD 1000000007

class Solution {
public:
    int maxArea(int h, int w, std::vector<int>& horizontalCuts, std::vector<int>& verticalCuts) {
        // O(N * log(N))
        long long a = 0, b = 0;
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        a = std::max(h - horizontalCuts.back(), horizontalCuts.front());
        b = std::max(w - verticalCuts.back(), verticalCuts.front());
        for (int i = 0; i < horizontalCuts.size() - 1; i++) {
            long long len = horizontalCuts[i + 1] - horizontalCuts[i];
            a = std::max(a, len);
        }
        for (int i = 0; i < verticalCuts.size() - 1; i++) {
            long long len = verticalCuts[i + 1] - verticalCuts[i];
            b = std::max(b, len);
        }
        long long result = a * b % FIELD;
        return static_cast<int>(result);
    }
};

int main(void) {
    Solution s;
}