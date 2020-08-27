// 15. 3Sum
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (std::pair<T1, T2> const &pair) const {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);
            return h1 ^ h2;
        }
    };
    public:
        std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
            // O(N ** 2) but so slow: Reimplementation required!
            std::vector<std::vector<int> > result;
            std::unordered_map<int, int> S;
            std::unordered_set<std::pair<int, int>, pair_hash> prefix;
            std::sort(nums.begin(), nums.end());
            int a, b, c;
            for (int i = 0; i < nums.size(); i++)
                S[nums[i]] = i;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    a = nums[i];
                    b = nums[j];
                    c = - a - b;
                    if (S.find(c) != S.end() && S[c] > j) {
                        if (prefix.find({a, b}) == prefix.end()) {
                            result.emplace_back(std::vector<int> {a, b, c});
                            prefix.insert({a, b});
                        }
                    } 
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    auto result = s.threeSum(nums);
    for (auto ans : result) {
        for (auto it : ans)
            std::cout << it << ' ';
        std::cout << std::endl;
    }
}