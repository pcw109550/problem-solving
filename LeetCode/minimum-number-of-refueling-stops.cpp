// 871. Minimum Number of Refueling Stops
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Solution {
    public:
        int minRefuelStops(int target, int startFuel, std::vector<std::vector<int> >& stations) {
            // O(N * log(N)))
            int result = 0;
            int N = stations.size();
            std::priority_queue<std::pair<int, int> > Q; // {fuel, pos}
            int totalFuel = startFuel;
            for (auto station : stations) {
                int pos = station[0];
                int fuel = station[1];
                if (pos > totalFuel) {
                    while (pos > totalFuel && !Q.empty()) {
                        result++;
                        auto next = Q.top(); Q.pop();
                        int nextPos = next.second;
                        int nextFuel = next.first;
                        totalFuel += nextFuel;
                    }
                    if (pos > totalFuel)
                        return -1;
                }
                Q.push({fuel, pos});                
            }
            while (totalFuel < target && !Q.empty()) {
                result++;
                auto next = Q.top(); Q.pop();
                int nextPos = next.second;
                int nextFuel = next.first;
                totalFuel += nextFuel;
            }
            return totalFuel >= target ? result : -1;
        }
};

int main(void) {
    Solution s;
}