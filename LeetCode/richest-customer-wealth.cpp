// 1672. Richest Customer Wealth
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // O(M * N)
        int result = 0;
        for (auto account : accounts) {
            int sum = accumulate(account.begin(), account.end(), 0);
            result = max(result, sum);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}