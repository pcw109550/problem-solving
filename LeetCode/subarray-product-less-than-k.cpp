// 713. Subarray Product Less Than K
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // O(N)
        int result = 0;
        int N = nums.size();
        int start = 0, end = -1;
        int cur = 1;
        while (end < N - 1 && start < N) {
            if (cur * nums[end + 1] < k) {
                cur *= nums[end + 1];
                end++;
                result += end - start + 1;
            } else {
                cur *= nums[end + 1];
                while (cur >= k && start <= end + 1) {
                    cur /= nums[start];
                    start++;
                }
                if (start > end + 1) {
                    cur = 1;
                    end = start;
                    end--;
                } else {
                    end++;
                    result += end - start + 1;
                }
            }
        }
        return result;
    }
};


class Solution2 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // O(N ** 2)
        int result = 0;
        unordered_map<int, int> M, temp;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            temp.clear();
            if (nums[i] >= k) {
                M.clear();
                continue;
            }
            temp[nums[i]]++;
            result++;
            for (auto it : M) {
                int cur = it.first * nums[i];
                if (cur < k) {
                    temp[cur] += it.second;
                    result += it.second;
                }
            }
            M = temp;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}