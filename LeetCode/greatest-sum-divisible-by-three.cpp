#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 10001

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // O(N * log(N))
        int N = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        vector<int> A, B;
        for (int i = 0; i < N; i++) {
            int cur = nums[i];
            result += cur;
            if (cur % 3 == 1)
                A.push_back(cur);
            else if (cur % 3 == 2)
                B.push_back(cur);
        }
        if (result % 3 == 1) {
            if (A.empty() && B.empty())
                return 0;
            while (B.size() < 2)
                B.push_back(MAX);
            int a = A[0];
            int b1 = B[0];
            int b2 = B[1];
            result -= min(a, b1 + b2);
        } else if (result % 3 == 2) {
            if (A.empty() && B.empty())
                return 0;
            while (A.size() < 2)
                A.push_back(MAX);
            int b = B[0];
            int a1 = A[0];
            int a2 = A[1];
            result -= min(b, a1 + a2);
        }
        return result;
    }
};