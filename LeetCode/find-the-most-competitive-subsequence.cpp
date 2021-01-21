// 1673. Find the Most Competitive Subsequence
#include <iostream>
#include <vector>
#include <stack>

class Solution {
    public:
        std::vector<int> mostCompetitive(std::vector<int>& nums, int k) {
            // O(N)
            std::vector<int> result;
            int N = nums.size();
            if (N == 0)
                return result;
            std::deque<int> S;
            for (int i = 0; i < N; i++) {
                while (!S.empty() && S.back() > nums[i] && k - S.size() + i < N )
                    S.pop_back();
                S.push_back(nums[i]);
            }
            while (!S.empty() && result.size() < k) {
                result.push_back(S.front());
                S.pop_front();
            }
            std::cout << std::endl;
            
            return result;
        }
};

int main(void) {
    Solution s;
}