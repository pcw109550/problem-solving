// 42. Trapping Rain Water
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // O(N)
        int result = 0;
        int N = height.size();
        // monotonic stack: decreasing
        stack<pair<int, int> > S; // {height, length}
        for (int i = 0; i < N; i++) {
            if (S.empty()) {
                S.push({height[i], 1});
            } else if (S.top().first > height[i]) {
                S.push({height[i], 1});
            } else if (S.top().first == height[i]) {
                S.top().second++;
            } else {
                while (!S.empty() && S.top().first < height[i]) {
                    int h = S.top().first;
                    int l = S.top().second;
                    S.pop();
                    if (S.empty()) {
                        S.push({height[i], 1});
                        break;
                    }
                    if (S.top().first < height[i]) {
                        result += l * (S.top().first - h);
                        S.top().second += l;
                    } else if (S.top().first == height[i]) {
                        result += l * (S.top().first - h);
                        S.top().second += l + 1;
                        break;
                    } else if (S.top().first > height[i]) {
                        result += l * (height[i] - h);
                        S.push({height[i], l + 1});
                        break;
                    }
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}