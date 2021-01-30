// 1588. Sum of All Odd Length Subarrays
#include <iostream>
#include <vector>

class Solution {
    public:
        int sumOddLengthSubarrays(std::vector<int>& arr) {
            // O(N)
            int result = 0;
            for (int i = 0; i < arr.size(); i++) {
                result += arr[i] * (i / 2 + 1) * ((arr.size() - 1 - i) / 2 + 1);
                if (i >= 1 && i <= arr.size() - 2)
                    result += arr[i] * ((i - 1) / 2 + 1) * ((arr.size() - 1 - (i + 1)) / 2 + 1);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}