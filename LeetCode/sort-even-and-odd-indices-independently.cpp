#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        // O(N * log(N))
        int N = nums.size();
        vector<int> result;
        int cnt = 0;
        vector<int> evens, odds;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0)
                evens.push_back(nums[i]);
            else
                odds.push_back(nums[i]);
        }
        sort(odds.begin(), odds.end(), greater<int>());
        sort(evens.begin(), evens.end());
        int p1 = 0, p2 = 0;
        while (cnt < N) {
            if (cnt % 2 == 0)
                result.push_back(evens[p1++]);
            else
                result.push_back(odds[p2++]);
            cnt++;
        }
        return result;
    }
};