// 1094. Car Pooling
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // O(N * log(N))
        int N = trips.size();
        vector<vector<int> > D;
        for (int i = 0; i < N; i++) {
            int num = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            D.push_back(vector<int> {start, num});
            D.push_back(vector<int> {end, - num});
        }
        int store = 0;
        sort(D.begin(), D.end());
        for (auto it : D) {
            int num = it[1];
            store += num;
            if (store > capacity)
                return false;
        }
        return true;
    }
};

int main(void) {
    Solution s;
}