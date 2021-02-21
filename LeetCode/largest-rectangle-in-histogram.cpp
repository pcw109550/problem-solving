// 84. Largest Rectangle in Histogram
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

class Solution {
    public:
        int largestRectangleArea(std::vector<int>& heights) {
            // O(N)
            int result = 0;
            std::stack<int> S; // monotonic stack storing index
            int N = heights.size();
            S.push(-1);
            for (int i = 0; i < N; i++) {
                while (S.top() != -1 && heights[S.top()] >= heights[i]) {
                    int j = S.top(); S.pop();
                    result = std::max(result, heights[j] * (i - S.top() - 1));
                }
                S.push(i);
            }
            while (S.top() != -1) {
                int j = S.top(); S.pop();
                result = std::max(result, heights[j] * (N - S.top() - 1));
            }
            return result;
        }
};

int main(void) {
    Solution s;
}