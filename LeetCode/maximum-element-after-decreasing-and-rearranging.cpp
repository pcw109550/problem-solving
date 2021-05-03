// 1846. Maximum Element After Decreasing and Rearranging
#include <algorithm>
#include <vector>

class Solution {
    public:
        int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
            // O(N * log(N))
            std::sort(arr.begin(), arr.end());
            int N = arr.size();
            arr[0] = 1;
            for (int i = 0; i < N - 1; i++)
                if (arr[i + 1] - arr[i] > 1)
                    arr[i + 1] = arr[i] + 1;
            return arr[N - 1];
        }
};

int main(void) {
    Solution s;
}