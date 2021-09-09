// 978. Longest Turbulent Subarray
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // O(N)
        int result = 1;
        int N = arr.size();
        if (N == 1)
            return 1;
        vector<int> D(N);
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] > arr[i + 1])
                D[i] = i % 2;
            else if (arr[i] < arr[i + 1])
                D[i] = (i + 1) % 2;
            else
                D[i] = -1;
        }
        int len = 0, cur = -2;
        for (int i = 0; i < N - 1; i++) {
            if (D[i] == -1) {
                result = max(result, len);
                len = 0;
                cur = -2;
            } else if (D[i] == 0) {
                if (cur == 0) {
                    len++;
                    result = max(result, len);
                } else {
                    result = max(result, len);
                    len = 2;
                    cur = 0;
                }
            } else if (D[i] == 1) {
                if (cur == 1) {
                    len++;
                    result = max(result, len);
                } else {
                    result = max(result, len);
                    len = 2;
                    cur = 1;
                }
            }
        }
        result = max(result, len);
        return result;
    }
};

int main(void) {
    Solution s;
}