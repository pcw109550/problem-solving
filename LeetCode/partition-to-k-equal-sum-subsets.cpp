// 698. Partition to K Equal Sum Subsets
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
    unordered_map<int, bool> M;
    int K, target;
    bool result;
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            // O(N * 2 ** N)
            int sum = 0;
            result = false;
            K = k;
            sort(nums.begin(), nums.end(), greater<int>());
            for (auto num : nums)
                sum += num;
            if (sum % k != 0)
                return false;
            target = sum / k;
            return backtrack(nums, 0, 0);
        }

        bool backtrack(vector<int>& nums, int state, int amount) {
            if (M.count(state))
                return M[state];
            auto dec = decode(state);
            int side = dec.first;
            int used = dec.second;
            if (amount == target) {
                amount = 0;
                side++;
            }
            if (side == K - 1)
                return true;
            bool temp = false;
            for (int i = 0; i < nums.size(); i++)
                if (!(used & (1 << i)) && (amount + nums[i] <= target))
                    if (backtrack(nums, encode(side, used | (1 << i)), amount + nums[i])) {
                        temp = true;
                        break;
                    }
            return M[state] = temp;
        }

        inline int encode(int side, int used) {
            return (side << 16) | used;
        }
    
        pair<int, int> decode(int state) {
            return {state >> 16, state & ((1 << 16) - 1)};
        }
};

int main(void) {
    Solution s;
}