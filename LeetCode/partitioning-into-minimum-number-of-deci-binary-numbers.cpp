// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
#include <algorithm>
#include <iostream>
#include <string>

class Solution {
    public:
        int minPartitions(std::string n) {
            // O(N)
            int result = 0;
            for (auto c : n)
                result = std::max(result, c - '0');
            return result;
        }
};

int main(void) {
    Solution s;
}