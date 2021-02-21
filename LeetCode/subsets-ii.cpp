// 90. Subsets II
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

class Solution {
    public:
        std::vector<std::vector<int> > subsetsWithDup(std::vector<int>& nums) {
            // O(N * 2 ** N)
            std::vector<std::vector<int> > result;
            std::unordered_set<std::string> S;
            int N = nums.size();
            std::sort(nums.begin(), nums.end());
            for (int i = 0; i < 1 << N; i++) {
                int temp = i;
                std::string key;
                std::vector<int> add;
                for (int j = 0; j < N; j++) {
                    if (temp & 1) {
                        add.push_back(nums[j]);
                        key.push_back(nums[j]);
                    }
                    temp >>= 1;
                }
                if (S.count(key))
                    continue;
                S.insert(key);
                result.push_back(add);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}