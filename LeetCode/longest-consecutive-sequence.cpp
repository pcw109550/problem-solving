// 128. Longest Consecutive Sequence
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        int longestConsecutive(std::vector<int>& nums) {
            // Time O(N)
            int result = 0;
            std::unordered_set<int> S;
            for (auto num : nums)
                S.insert(num);
            while (!S.empty()) {
                int len = 1;
                auto it = *S.begin();
                S.erase(it);
                int probe = it;
                while (S.count(probe + 1)) {
                    len++;
                    S.erase(++probe);
                }
                probe = it;
                while (S.count(probe - 1)) {
                    len++;
                    S.erase(--probe);
                }
                result = std::max(result, len);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}