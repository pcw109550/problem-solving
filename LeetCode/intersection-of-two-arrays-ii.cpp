// 350. Intersection of Two Arrays II
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
            // O(N)
            std::vector<int> result;
            std::unordered_multiset<int> S;
            for (auto num : nums1)
                S.insert(num);
            for (auto num : nums2) {
                auto it = S.find(num);
                if (it != S.end()) {
                    result.push_back(num);
                    S.erase(it);
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}