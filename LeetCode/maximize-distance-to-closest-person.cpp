// 849. Maximize Distance to Closest Person
#include <iostream>
#include <vector>

class Solution {
    public:
        int maxDistToClosest(std::vector<int>& seats) {
            // O(N)
            int Max = 0, start = -1;
            int N = seats.size();
            for (int i = 0; i < N; i++) {
                if (seats[i] == 1) {
                    if (start == -1)
                        Max = std::max(Max, i - start - 1);
                    else
                        Max = std::max(Max, (i - start) / 2);
                    start = i;
                }
            }
            Max = std::max(Max, N - start - 1);
            return Max;
        }
};

int main(void) {
    Solution s;
    std::vector<int> seats {1, 0, 0, 1};
    int output = s.maxDistToClosest(seats);
    std::cout << output;
}
