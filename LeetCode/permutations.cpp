// 46. Permutations
#include <algorithm>
#include <iostream>
#include <vector>

class Solution1 {
    public:
        std::vector<std::vector<int> > permute(std::vector<int>& nums) {
            // O(n * log(n) + n!) using stl
            // Or use prev_permutation for O(n + n!)
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int> > result;
            do {
                result.emplace_back(nums);
            } while (std::next_permutation(nums.begin(), nums.end()));
            return result;
        }
};

class Solution2 {
    public:
        std::vector<std::vector<int> > permute(std::vector<int>& nums) {
            // O(n + n!)
            std::vector<std::vector<int> > result;
            std::vector<int> dummy;
            for (int i = 0; i < nums.size(); i++)
                dummy.emplace_back(i);
            do {
                std::vector<int> temp;
                for (int i = 0; i < dummy.size(); i++)
                    temp.emplace_back(nums[dummy[i]]); 
                result.emplace_back(temp);
            } while (std::next_permutation(dummy.begin(), dummy.end()));
            return result;
        }
};

int main(void) {
    Solution2 s;
    std::vector<int> nums {0, -1, 1};
    auto result = s.permute(nums);
    for (auto it : result) {
        for (auto elem : it) {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
}