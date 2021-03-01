// 575. Distribute Candies
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        int distributeCandies(std::vector<int>& candyType) {
            // O(N)
            std::unordered_set<int> S;
            for (auto candy : candyType)
                S.insert(candy);
            return S.size() <= candyType.size() / 2 ? S.size() : candyType.size() / 2;
        }
};

int main(void) {
    Solution s;
}