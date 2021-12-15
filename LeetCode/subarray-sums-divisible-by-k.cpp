// 974. Subarray Sums Divisible by K
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // O(N)
        int result = 0;
        int sum = 0;
        unordered_map<int, int> M;
        M[0]++;
        for (auto num : nums) {
            sum = ((sum + num) % k + k) % k;
            M[sum]++;
        }
        for (auto it : M)
            result += it.second * (it.second - 1) / 2;
        return result;
    }
};

int main(void) {
    Solution s;
}