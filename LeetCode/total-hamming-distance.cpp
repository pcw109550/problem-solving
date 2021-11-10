// 477. Total Hamming Distance
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // O(N)
        int result = 0;
        int c = 1, N = nums.size();
        while (c <= 1000000000) {
            int k = 0;
            for (auto num : nums)
                if (num & c)
                    k++;
            result += k * (N - k);
            c <<= 1;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}