// 899. Orderly Queue
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        // O(N ** 2)
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for (int i = 1; i < S.length(); i++)
            res = min(res, S.substr(i) + S.substr(0, i));
        return res;
    }
};

int main(void) {
    Solution s;
}