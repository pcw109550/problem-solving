// 442. Find All Duplicates in an Array
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> findDuplicates(std::vector<int>& nums) {
            // Time O(N) Space O(1)
            std::vector<int> result;
            if (nums.size() == 1)
                return result;
            int N = nums.size();
            for (int i = 0; i < N; i++)
                nums[i] %= N;
            for (int i = 0; i < N; i++)
                nums[nums[i] % N] += N;
            for (int i = 0; i < N; i++)
                if (nums[i] / N == 2)
                    result.push_back(i % N != 0 ? i : N);
            return result;
        }
};

int main(void) {
    Solution s;
}