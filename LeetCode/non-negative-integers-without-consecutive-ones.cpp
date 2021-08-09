// 600. Non-negative Integers without Consecutive Ones
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        // O(log(N))
        int result = 1;
        int cnt = 1;
        int sum = 0;
        vector<int> D {0, 0};
        vector<int> L {1, 1};
        if (n <= 2)
            return n + 1;
        if (n >= 1)
            result++;
        while (true) {
            int next = cnt;
            sum += D[D.size() - 2];
            next += sum;
            cnt <<= 1;
            D.push_back(next);
            L.push_back(cnt);
            if (n >= 2 * cnt - 1)
                result += cnt - next;
            else
                break;
        }
        int d = n - cnt + 1; // cnt <= < 2 * cnt
        int k = 0;
        int idx = 0;
        while (d > 0) {
            d = min(d, cnt / 2);
            if (k + L[idx] > d)
                break;
            while (k + L[idx] <= d) {
                result += L[idx] - D[idx];
                k += L[idx];
                idx++;
            }
            d -= k;
            idx = 0;
            cnt = k;
            k = 0;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}