// 1642. Furthest Building You Can Reach
#include <iostream>
#include <queue>
#include <vector>

class Solution {
    public:
        int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
            // O(N * log(N))
            int result = -1;
            int N = heights.size();
            std::priority_queue<int> Q;
            for (int i = 0; i < N - 1; i++) {
                if (heights[i] >= heights[i + 1])
                    continue;
                else {
                    int delta = heights[i + 1] - heights[i];
                    if (bricks >= delta) {
                        Q.push(delta);
                        bricks -= delta;
                    } else if (ladders > 0) {
                        ladders--;
                        int save = Q.empty() ? 0 : Q.top();
                        if (save < delta)
                            continue;
                        Q.push(delta);
                        bricks += save;
                        bricks -= delta;
                        if (save)
                            Q.pop();
                    } else {
                        result = i;
                        break;
                    }
                }
            }
            result = result == -1 ? N - 1 : result;
            return result;
        }
};

int main(void) {
    Solution s;
}