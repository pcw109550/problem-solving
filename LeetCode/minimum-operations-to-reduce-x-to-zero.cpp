// 1658. Minimum Operations to Reduce X to Zero
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int minOperations(std::vector<int>& nums, int x) {
            // O(N)
            int result = 1 << 30;
            int N = nums.size();
            std::vector<int> backward(N, false);
            std::unordered_map<int, int> M;
            backward[N - 1] = nums[N - 1];
            M[backward[N - 1]] = N - 1;
            for (int i = N - 2; i >= 0; i--) {
                backward[i] = backward[i + 1] + nums[i];
                M[backward[i]] = i;
            }
            if (M.find(x) != M.end())
                result = N - 1 - M[x] + 1;
            int acc = nums[0];
            for (int i = 0; i < N; i++) {
                auto temp = x - acc;
                if (i + 1 < N)
                    acc += nums[i + 1];
                if (temp == 0) {
                    result = std::min(result, i + 1);
                    continue;
                }
                if (M.find(temp) != M.end()) {
                    auto idx = M[temp];
                    if (idx <= i)
                        continue;
                    result = std::min(result, i + 1 + N - 1 - M[temp] + 1);
                }
            }
            return result == 1 << 30 ? -1 : result;
        }
};

int main(void) {
    Solution s;
}