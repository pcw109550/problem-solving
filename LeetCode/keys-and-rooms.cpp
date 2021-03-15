// 841. Keys and Rooms
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        bool canVisitAllRooms(std::vector<std::vector<int> >& rooms) {
            // O(N)
            int N = rooms.size();
            std::vector<bool> visited (N, false);
            int num_opened = 0;
            std::queue<int> Q;
            Q.push(0); visited[0] = true; num_opened++;
            while (!Q.empty()) {
                int current = Q.front(); Q.pop();
                for (auto cand : rooms[current]) {
                    if (visited[cand])
                        continue;
                    visited[cand] = true;
                    num_opened++;
                    Q.push(cand);
                }
            }
            return num_opened == N;
        }
};

int main(void) {
    Solution s;
}