// 75. Sort Colors
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            // O(N)
            int N = nums.size();
            if (N == 0)
                return;
            int start = 0, end = N - 1;
            for (int i = 0; i < N; i++) {
                if (nums[i] == 2 && i < end) {
                    swap(nums[i], nums[end]);
                    end--;
                    i--;
                } else if (nums[i] == 0 && i > start) {
                    swap(nums[i], nums[start]);
                    start++;
                    i--;
                }
            }
        }
};

int main(void) {
    Solution s;
}