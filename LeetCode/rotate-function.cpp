// 396. Rotate Function
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int maxRotateFunction(std::vector<int>& nums) {
            // O(N)
            int N = nums.size();
            long long result = INT_MIN;
            long long temp = 0, chunk = 0;
            for (long long i = 0; i < N; i++) {
                temp += i * nums[i];
                chunk += nums[i];
            }
            for (int i = 0; i < N; i++) {
                temp += chunk;
                temp -= static_cast<long long>(nums[N - i - 1]) * N;
                result = std::max(result, temp);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}