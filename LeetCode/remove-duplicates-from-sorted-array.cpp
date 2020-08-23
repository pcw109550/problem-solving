// 26. Remove Duplicates from Sorted Array
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            // O(N)
            int count = 0;
            for(int i = 1; i < nums.size(); i++){
                if (nums[i] == nums[i - 1])
                    count++;
                else
                    nums[i - count] = nums[i];
            }
            nums.resize(nums.size() - count);
            return nums.size();
        }
};

class Solution2 {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            // O(N)
            nums.erase(std::unique(nums.begin(),nums.end()),nums.end());
            return nums.size();
        }
};

class Solution3 {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            // O(N ** 2)
            if (nums.size() == 0)
                return 0;
            auto it = nums.begin();
            while (true) {
                if (it + 1 == nums.end())
                    break;
                if (*it == *(it + 1))
                    nums.erase(it + 1);
                else
                    it++;
            }
            return nums.size();
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {0, 1, 1, 1, 2, 2, 3, 3, 4};
    int result = s.removeDuplicates(nums);
    std::cout << result << std::endl;
    for (auto num : nums)
        std::cout << num << ' ';
}