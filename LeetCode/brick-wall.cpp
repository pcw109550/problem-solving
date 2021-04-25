// 554. Brick Wall
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int leastBricks(std::vector<std::vector<int> >& wall) {
            // O(M * N)
            int temp = 0, result = 0;
            int probe = 0;
            std::unordered_map<int, int> M;
            for (auto w : wall) {
                probe = 0;
                for (auto it : w) {
                    probe += it;
                    M[probe]++;
                }
            }
            M.erase(probe);
            for (auto it : M)
                temp = std::max(temp, it.second);
            result = wall.size() - temp;
            return result;
        }
};

int main(void) {
    Solution s;
}