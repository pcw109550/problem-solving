// 611. Valid Triangle Number
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // O(N ** 2)
        int result = 0;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int M = *max_element(nums.begin(), nums.end());
        vector<int> cnt (M + 1, 0);
        vector<int> D (M + 1, 0);
        for (auto num : nums)
            cnt[num]++;
        for (int i = 0; i <= M; i++)
            D[i] = (i >= 1 ? D[i - 1] : 0) + cnt[i];
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                int x = nums[j] + nums[i]; // b + a
                int y = nums[j] - nums[i]; // b - a
                if (x > M + 1)
                    x = M + 1;
                if (y < 0)
                    y = 0;
                // b + a > c > b - a
                int k = (x >= 1 ? D[x - 1] : 0) - D[y];
                if (x > nums[i] && nums[i] > y)
                    k--;
                if (x > nums[j] && nums[j] > y)
                    k--;
                if (k < 0)
                    k = 0;
                result += k;
            }
        result /= 3;
        return result;
    }
};

int main(void) {
    Solution s;
}