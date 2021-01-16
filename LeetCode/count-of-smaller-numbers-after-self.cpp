// 315. Count of Smaller Numbers After Self
#include <iostream>
#include <vector>

class Solution {
    std::vector<int> D;
    
    public:
        std::vector<int> countSmaller(std::vector<int>& nums) {
            // O(N log(K)) using BIT
            int N = nums.size();
            std::vector<int> result (N);
            D = std::vector<int> (20002, 0);
            for (int i = N - 1; i >= 0; i--) {
                update(nums[i] + 10001);
                result[i] = sum(nums[i] + 10000);
            }
            return result;
        }
    
        void update(int idx) {
            while (idx <= 20001) {
                D[idx]++;
                idx += idx & -idx;
            }
        }
    
        int sum(int idx) {
            int result = 0;
            while (idx > 0) {
                result += D[idx];
                idx -= idx & -idx;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}