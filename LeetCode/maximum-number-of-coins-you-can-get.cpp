#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // O(N * log(N))
        int N = piles.size() / 3;
        int result = 0;
        sort(piles.begin(), piles.end());
        for (int i = 0; i < N; i++)
            result += piles[N + 2 * i];
        return result;
    }
};