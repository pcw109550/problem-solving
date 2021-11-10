// 1389. Create Target Array in the Given Order
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        // O(N ** 2)
        int N = nums.size();
        vector<int> target(N, -1);
        for (int i = 0; i < N; i++) {
            auto it = target.begin();
            advance(it, index[i]);
            target.insert(it, nums[i]);
        }
        while (target.back() == -1)
            target.pop_back();
        return target;
    }
};

int main(void) {
    Solution s;
}