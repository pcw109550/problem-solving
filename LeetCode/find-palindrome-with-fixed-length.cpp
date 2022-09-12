#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        // O(N)
        vector<long long> result;
        int N = queries.size();
        long long Max = (long long)pow((double)10, intLength / 2 + intLength % 2 - 1) * 9;
        long long base = (long long)pow((double)10, intLength / 2 + intLength % 2 - 1);
        for (int i = 0; i < N; i++) {
            if (queries[i] > Max) {
                result.push_back(-1);
                continue;
            }
            long long cur = base + queries[i] - 1;
            long long cur_res = cur;
            vector<long long> temp;
            for (int i = 0; i < intLength / 2 + intLength % 2; i++) {
                temp.push_back(cur % 10);
                cur /= 10;
            }
            for (int j = intLength % 2; j < temp.size(); j++) {
                cur_res *= 10;
                cur_res += temp[j];
            }
            result.push_back(cur_res);
        }
        return result;
    }
};