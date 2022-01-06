// 1299. Replace Elements with Greatest Element on Right Side
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // O(N)
        int N = arr.size();
        vector<int> result (N);
        int Max = arr[N - 1];
        result[N - 1] = -1;
        for (int i = N - 2; i >= 0; i--) {
            result[i] = Max;
            Max = max(Max, arr[i]);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}