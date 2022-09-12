#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // O(M + N)
        int M = rolls.size();
        int sum_all = mean * (M + n);
        int sum_partial = accumulate(rolls.begin(), rolls.end(), 0);
        int delta = sum_all - sum_partial;
        if (delta < n)
            return vector<int> ();
        if (delta > 6 * n)
            return vector<int> ();
        vector<int> result (n, delta / n);
        for (int i = 0; i < delta % n; i++)
            result[i]++;
        return result;
    }
};