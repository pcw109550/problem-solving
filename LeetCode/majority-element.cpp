// 169. Majority Element
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        int majorityElement(std::vector<int>& nums) {
            // Boyer-Moore Voting Algorithm
            // Time O(N) Space O(1) 
            int result = -1, cnt = 0;
            for (auto num : nums) {
                if (cnt == 0)
                    result = num;
                cnt += num == result ? 1 : -1;
            }
            return result;
        }
};

class Solution2 {
    public:
        int majorityElement(std::vector<int>& nums) {
            // Time O(N) Space O(N)
            int result = -1;
            int n = nums.size();
            std::unordered_map<int, int> M;
            for (auto num : nums) {
                if (M.find(num) == M.end())
                    M[num] = 1;
                else
                    M[num]++;
                if (M[num] > n / 2) {
                    result = num;
                    break;  
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {2, 2, 1, 1, 1, 1, 2};
    int result = s.majorityElement(nums);
    std::cout << result;
}