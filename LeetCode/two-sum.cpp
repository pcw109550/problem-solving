// 1. Two Sum
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution1 {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            // O(n ** 2)
            int size = nums.size();
            for (int i = 0; i < size; i++)
                for (int j = i + 1; j < size; j++) {
                    if (nums[i] + nums[j] == target)
                        return std::vector<int> {i, j};
                }
            return std::vector<int>();
        }
};

class Solution2 {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            // O(n)
            // {value : idx}
            std::unordered_map<int, int> Map;
            for (int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i];
                auto it = Map.find(complement);
                if (it != Map.end())
                    return std::vector<int> {it->second, i};
                Map[nums[i]] = i;
            }
            return std::vector<int>();
        }
};

int main(void) {
    Solution2 s;
    std::vector<int> n1 {2, 7, 11, 15};
    int t1 = 26;
    std::vector<int> r1 = s.twoSum(n1, t1);
    for (auto it : r1)
        std::cout << it << ' ';
}