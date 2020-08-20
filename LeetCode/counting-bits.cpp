// 338. Counting Bits
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> countBits(int num) {
            // O(N)
            std::vector<int> result {0};
            int cnt = 1, range = 1;
            while (cnt <= num) {
                for (int i = 0; i < range && cnt <= num; i++, cnt++)
                    result.push_back(1 + result[i]);
                range <<= 1;
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> result = s.countBits(100);
    for (auto it : result)
        std::cout << it << ' ';
}