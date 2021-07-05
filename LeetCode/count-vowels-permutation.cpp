// 1220. Count Vowels Permutation
#include <iostream>
#include <vector>
using namespace std;
#define FIELD 1000000007

class Solution {
    public:
        int countVowelPermutation(int n) {
            // O(N)
            vector<vector<long long> > D(n, vector<long long> (5, 0));
            for (int i = 0; i < 5; i++)
                D[0][i] = 1;
            for (int i = 1; i < n; i++) {
                D[i][0] = D[i - 1][1];
                D[i][1] = (D[i - 1][0] + D[i - 1][2]) % FIELD;
                D[i][2] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][3] + D[i - 1][4]) % FIELD;
                D[i][3] = (D[i - 1][2] + D[i - 1][4]) % FIELD;
                D[i][4] = D[i - 1][0];
            }
            long long result = 0;
            for (int i = 0; i < 5; i++)
                result += D[n - 1][i];
            result %= FIELD;
            return result;
        }
};

int main(void) {
    Solution s;
}