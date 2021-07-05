// 1004. Max Consecutive Ones III
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            // O(N)
            int N = nums.size();
            int result = 0, start = 0, end = 0;
            int usage = 0;
            deque<int> Q;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {
                    end++;
                    result = max(result, end - start);
                } else if (nums[i] == 0) {
                    if (usage < k) {
                        usage++;
                        end++;
                        Q.push_back(i);
                        result = max(result, end - start);
                    } else if (k != 0) {
                        end++;
                        if (!Q.empty()) {
                            start = Q.front() + 1;
                            Q.pop_front();
                        }
                        Q.push_back(i);
                        result = max(result, end - start);
                    } else {
                        start = end = i;
                    }
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}