// 78. Subsets
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int> > subsets(std::vector<int>& nums) {
            // O(N * 2 ** N)
            std::vector<std::vector<int> > result;
            std::vector<int> comb, subset;
            int n = nums.size(), i;
            for (int k = 1; k <= n; k++) {
                comb.resize(k, 0);
                i = 0;
                while (i >= 0) {
                    comb[i]++;
                    if (comb[i] > n)
                        i--;
                    else if (i == k - 1) {
                        subset.clear();
                        for (int j = 0; j < k; j++)
                            subset.emplace_back(nums[comb[j] - 1]);
                        result.push_back(subset);
                    } else {
                        i++;
                        comb[i] = comb[i - 1];
                    }
                }
                comb.clear();
            }
            result.push_back(comb);
            return result;   
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {7, 8, 9};
    auto result = s.subsets(nums);
    for (auto subset : result) {
        for (auto elem : subset)
            std::cout << elem << ' ';
        std::cout << std::endl;
    }   
}