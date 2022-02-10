// 967. Numbers With Same Consecutive Differences
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        // O(N * 2 ** K)
        vector<int> result;
        queue<pair<int, int> > Q;
        for (int i = 1; i <= 9; i++)
            Q.push({i, 1});
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int cur_digit = cur.first;
            if (cur.second == n) {
                result.push_back(cur_digit);
                continue;
            }
            if (k == 0) 
                Q.push({cur_digit * 10 + cur_digit % 10, cur.second + 1});
            else {
                if (cur_digit % 10 - k >= 0)
                    Q.push({cur_digit * 10 + cur_digit % 10 - k, cur.second + 1});
                if (cur_digit % 10 + k <= 9)
                    Q.push({cur_digit * 10 + cur_digit % 10 + k, cur.second + 1});
            }
        }        
        return result;
    }
};

int main(void) {
    Solution s;
}
