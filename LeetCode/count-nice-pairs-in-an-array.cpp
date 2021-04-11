// 1814. Count Nice Pairs in an Array
#include <iostream>
#include <vector>
#include <unordered_map>
#define FIELD 1000000007

class Solution {
    public:
        int countNicePairs(std::vector<int>& nums) {
            // O(N)
            long long result = 0;
            std::unordered_map<int, long long> M;
            for (auto num : nums)
                M[num - rev(num)]++;
            for (auto it : M) {
                auto cnt = it.second;
                result += cnt * (cnt - 1) / 2;
                result %= FIELD;
            }
            return static_cast<int>(result);
        }

        inline int rev(int n) {
            int result = 0;
            while (n) {
                result *= 10;
                result += n % 10;
                n /= 10;
            }
            return result;
        }
}; 

int main(void) {
    Solution s;
}