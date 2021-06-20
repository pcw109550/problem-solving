// 1287. Element Appearing More Than 25% In Sorted Array
#include <iostream>
#include <vector>

class Solution {
    public:
        int findSpecialInteger(std::vector<int>& arr) {
            // Time O(N) Space O(1)
            int N = arr.size();
            int cnt = 1;
            int cur = -1;
            for (int i = 0; i < N; i++) {
                if (cur != arr[i]) {
                    cnt = 1;
                    cur = arr[i];
                } else {
                    cnt++;
                }
                if (cnt > N / 4)
                    return cur;
            }
            return cur;
        }
};

int main(void) {
    Solution s;
}