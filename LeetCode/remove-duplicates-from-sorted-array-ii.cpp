// 80. Remove Duplicates from Sorted Array II
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time O(N) Space O(1)
        int N = nums.size(), K = N;
        int ind = 11111;
        int cur = nums[0], cur_cnt = 1;
        nums.push_back(-ind);
        for (int i = 1; i < N + 1; i++) {
            if (nums[i] == cur)
                cur_cnt++;
            else {
                for (int j = i - 1; j >= i - cur_cnt + 2; j--) {
                    nums[j] = ind;
                    K--;
                }
                cur = nums[i];
                cur_cnt = 1;
            }
        }
        nums.pop_back();
        
        int p1 = 0, p2 = 0;
        while (p1 < N && p2 < N) {
            if (nums[p1] == ind) {
                p2 = max(p2, p1);
                while (p2 < N && nums[p2] == ind) {
                    p2++;
                }
                if (p2 < N)
                    swap(nums[p1], nums[p2]);
                p2++;
            }
            p1++;
        }
        
        return K;
    }
};

int main(void) {
    Solution s;
}
