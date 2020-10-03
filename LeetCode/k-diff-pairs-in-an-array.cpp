// 532. K-diff Pairs in an Array
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

class Solution {
    public:
        int findPairs(std::vector<int>& nums, int k) {
            // O(N log(N))
            int result = 0;
            std::sort(nums.begin(), nums.end());
            std::unordered_set<int> set, cnt;
            std::vector<int> unique;
            for (auto it : nums) {
                if (set.find(it) != set.end()) {
                    if (cnt.find(it) == cnt.end()) {
                        result++;
                        cnt.insert(it);
                    }
                } else {
                    set.insert(it);
                    unique.emplace_back(it);
                }
            }
            if (k == 0)
                return result;
            result = 0;
            for (auto it : unique)
                if (set.find(it + k) != set.end())
                    result++;
            return result;
        }
};

class Solution2 {
    public:
        int findPairs(std::vector<int>& nums, int k) {
            // O(N ** 2)
            int result = 0;
            std::unordered_set<int> set, cnt;
            std::vector<int> unique;
            int N = nums.size();
            for (auto it : nums) {
                if (set.find(it) != set.end() && cnt.find(it) == cnt.end()) {
                    result++;
                    cnt.insert(it);
                } else {
                    set.insert(it);
                }
            }
            if (k == 0)
                return result;
            result = 0;
            for (auto it : set)
                unique.emplace_back(it);
            int M = unique.size();
            for (int i = 0; i < M; i++) {
                for (int j = i + 1; j < M; j++) {
                    if (abs(unique[i] - unique[j]) == k)
                        result++;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {1,1,1,2,1};
    int k = 1;
    std::cout << s.findPairs(nums, k);
}