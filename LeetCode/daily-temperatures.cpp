// 739. Daily Temperatures
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // O(N)
        int N = temperatures.size();
        vector<int> result (N, 0);
        stack<int> S;
        for (int i = 0; i < N; i++) {
            if (S.empty() || temperatures[S.top()] >= temperatures[i])
                S.push(i);
            else {
                while (!S.empty() && temperatures[S.top()] < temperatures[i]) {
                    auto it = S.top(); S.pop();
                    result[it] = i - it;
                }
                S.push(i);
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}