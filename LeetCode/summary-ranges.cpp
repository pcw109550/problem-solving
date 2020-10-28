// 228. Summary Ranges
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::vector<std::string> summaryRanges(std::vector<int>& nums) {
            // O(N)
            std::vector<std::string> result;
            if (nums.size() == 0)
                return result;
            auto it = nums.begin();
            int start = *it, end = *it; it++;
            while (it != nums.end()) {
                if (end + 1 != *it) {
                    result.push_back(format(start, end));
                    start = end = *it;
                } else {
                    end++;
                }
                it++;
            }
            result.push_back(format(start, end));
            return result;
        }

        inline std::string format(int start, int end) {
            if (start == end)
                return std::to_string(start);
            return std::to_string(start) + "->" + std::to_string(end);
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {0, 2, 3, 4, 6, 8, 9};
    auto result = s.summaryRanges(nums);
    for (auto &it: result)
        std::cout << it << ' ';
}