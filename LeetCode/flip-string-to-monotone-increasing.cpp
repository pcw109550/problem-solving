// 926. Flip String to Monotone Increasing
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // O(N)
        int result = INT_MAX;
        int N = s.size();
        vector<int> D (N + 1, 0);
        for (int i = 0; i < N; i++)
            D[i + 1] = D[i] + (s[i] == '1');
        for (int i = 0; i < N; i++) {
            int a = D[i + 1];
            int b = N - i - 1 - (D[N] - D[i]);
            result = min(result, a + b);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}