// 349. Intersection of Two Arrays
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
            // O(N)
            std::vector<int> result;
            std::unordered_set<int> S;
            std::unordered_set<int> R;
            if (nums1.size() > nums2.size())
                std::swap(nums1, nums2);
            for (auto num : nums1)
                S.insert(num);
            for (auto num : nums2)
                if (S.count(num))
                    R.insert(num);
            for (auto it : R)
                result.push_back(it);
            return result;
        }
};

int main(void) {
    Solution s;
}