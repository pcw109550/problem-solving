// 217. Contains Duplicate
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        bool containsDuplicate(std::vector<int>& nums) {
            // O(N)
            std::unordered_set<int> S;
            for (auto num : nums) {
                if (S.count(num))
                    return true;
                S.insert(num);
            }
            return false;
        }
};

int main(void) {
    Solution s;
}