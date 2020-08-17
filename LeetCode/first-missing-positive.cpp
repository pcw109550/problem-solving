// 41. First Missing Positive
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution1 {
    public:
        int firstMissingPositive(std::vector<int>& nums) {
            // O(k * log(k)) where k < n
            int result = 1;
            nums.erase(std::remove_if(nums.begin(),
                nums.end(), [](int x) { return x <= 0; }), nums.end());
            std::sort(nums.begin(), nums.end());
            for (auto it : nums)
                if (it != result)
                    if (it == result - 1)
                        continue;
                    else
                        break;
                else
                    result++;
            return result;
        }
};

class Solution2 {
    public:
        int firstMissingPositive(std::vector<int>& nums) {
            // O(n)
            std::unordered_set<int> Map;
            int result = 1;
            for (auto it : nums)
                if (it > 0)
                    Map.insert(it);
            while (true) {
                if (Map.find(result) == Map.end())
                    break;
                result++;
            }
            return result;
        }
};

int main(void) {
    Solution2 s;
    std::vector<int> nums {0, 2, 2, 1, 1};
    int result = s.firstMissingPositive(nums);
    std::cout << result;
}