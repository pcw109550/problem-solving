// 134. Gas Station
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // O(N)
        int sum = 0, N = gas.size();
        int result = 0, Min = INT_MAX;
        for (int i = 0; i < N; i++) {
            sum = sum + gas[i] - cost[i];
            if (Min > sum) {
                Min = sum;
                result = (i + 1) % N;
            }
        }
        if (sum < 0)
            return -1;
        return result;
    }
};

int main(void) {
    Solution s;
}
