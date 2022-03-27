// 2023. Number of Pairs of Strings With Concatenation Equal to Target
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        // O(N ** 2)
        int result = 0;
        unordered_map<string, int> M;
        for (auto num : nums)
            M[num]++;
        int N = nums.size();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (i != j && nums[i] + nums[j] == target)
                    result++;
        return result;
    }
};

int main(void) {
    Solution s;
}

