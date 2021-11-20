// 503. Next Greater Element II
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // O(N)
        int N = nums.size();
        vector<int> result(N);
        stack<int> S;
        for (int i = 2 * N - 1; i >= 0; i--) {
            if (S.empty()) {
                S.push(nums[i % N]);
                result[i % N] = -1;
            } else {
                while (!S.empty() && S.top() <= nums[i % N])
                    S.pop();
                if (S.empty())
                    result[i % N] = -1;
                else
                    result[i % N] = S.top();
                S.push(nums[i % N]);
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
