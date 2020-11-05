// 1217. Minimum Cost to Move Chips to The Same Position
#include <iostream>
#include <vector>

class Solution {
    public:
        int minCostToMoveChips(std::vector<int>& position) {
            // O(N)
            int N = position.size();
            int num_odd = 0;
            for (auto &pos: position)
                if (pos % 2)
                    num_odd++;
            int result = std::min(num_odd, N - num_odd);
            return result;
        }
};

int main(void) {
    Solution s;
}