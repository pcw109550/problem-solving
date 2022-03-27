// 1991. Find the Middle Index in Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // O(N)
        int result = -1;
        int N = nums.size();
        vector<int> D(N + 1);
        for (int i = 0; i < N; i++)
            D[i + 1] = D[i] + nums[i];
        for (int i = 1; i <= N; i++) {
            int l = D[i - 1] - D[0];
            int r = D[N] - D[i];
            if (l == r) {
                result = i - 1;
                break;
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
