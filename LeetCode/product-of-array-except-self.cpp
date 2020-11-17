// 238. Product of Array Except Self
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums) {
            // Time O(N) Space O(1)
            int N = nums.size(), R = 1;
            std::vector<int> result (N, 1);
            for (int i = 1; i < N; i++)
                result[i] = result[i - 1] * nums[i - 1];
            for (int i = N - 1; i >= 0; i--) {
                result[i] *= R;
                R *= nums[i];
            }
            return result;
        }
};

class Solution2 {
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums) {
            // Time O(N) Space O(1)
            int N = nums.size(); int acc1 = 1, acc2 = 1;
            std::vector<int> result (N, 1);
            for (int i = 0; i < N / 2; i++) {
                result[2 * i] *= nums[2 * i + 1];
                result[2 * i + 1] *= nums[2 * i];
            }
            if (N % 2 == 1) {
                for (int i = 0; i <= N - 2; i++)
                    result[i] *= nums[N - 1];
            }
            for (int i = 0; i < N; i++) {
                if (i >= 2 && i % 2 == 0) {
                    result[i] *= acc1;
                    if (i + 1 < N)
                        result[i + 1] *= acc1;
                }
                acc1 *= nums[i];
            }
            for (int i = N - 1 - N % 2; i >= 0; i--) {
                if (i <= N - 1 - N % 2 - 2 && i % 2 == 1) {
                    result[i] *= acc2;
                    if (i - 1 >= 0)
                        result[i - 1] *= acc2; 
                }
                acc2 *= nums[i];
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {1, 2, 3, 4};
    auto result = s.productExceptSelf(nums);
    for (auto &it: result)
        std::cout << it << ' ';
}