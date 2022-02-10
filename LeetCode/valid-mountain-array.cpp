// 941. Valid Mountain Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // O(N)
        int N = arr.size(), cnt = 0, cntl = 0, cntr = 0;
        for (int i = 1; i < N - 1; i++) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
                cnt++;
            if (arr[i - 1] < arr[i] && arr[i] < arr[i + 1])
                cntl++;
            if (arr[i - 1] > arr[i] && arr[i] > arr[i + 1])
                cntr++;
        }
        return cnt == 1 && (cnt + cntl + cntr == N - 2);
    }
};

int main(void) {
    Solution s;
}
