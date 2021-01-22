// 11. Container With Most Water
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int maxArea(std::vector<int>& height) {
            // O(N)
            int result = 0;
            int N = height.size();
            int l = 0, r = N - 1;
            while (l < r) {
                result = std::max(result, (r - l) * std::min(height[l], height[r]));
                if (height[l] < height[r])
                    l++;
                else
                    r--;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}