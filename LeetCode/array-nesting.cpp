// 565. Array Nesting
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        int arrayNesting(std::vector<int>& nums) {
            // O(N)
            int N = nums.size();
            int result = 0;
            std::vector<bool> visited (N, false);
            for (int i = 0; i < N; i++) {
                if (visited[i])
                    continue;
                int temp = i;
                int idx = 0;
                std::unordered_set<int> S;
                while (!S.count(temp)) {
                    idx++;
                    visited[temp] = true;
                    S.insert(temp);
                    temp = nums[temp];
                }
                result = std::max(result, idx);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}