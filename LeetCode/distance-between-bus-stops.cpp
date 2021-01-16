// 1184. Distance Between Bus Stops
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination) {
            // O(N)
            int acc = 0;
            int part = 0;
            if (start > destination)
                std::swap(start, destination);
            for (int i = 0; i < distance.size(); i++) {
                acc += distance[i];
                if (start <= i && i < destination)
                    part += distance[i];
            }
            return std::min(part, acc - part);
        }
};

int main(void) {
    Solution s;
}