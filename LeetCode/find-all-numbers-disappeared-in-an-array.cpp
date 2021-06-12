// 448. Find All Numbers Disappeared in an Array
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
            // Time O(N) Space O(1)
            std::vector<int> result;
            int N = nums.size();
            for (int i = 0; i < N; i++)
                nums[i] %= N;
            for (int i = 0; i < N; i++)
                nums[nums[i] % N] += N;
            for (int i = 0; i < N; i++)
                if (nums[i] < N)
                    result.push_back(i == 0 ? N : i);
            return result;
        }
};

int main(void) {
    Solution s;
}