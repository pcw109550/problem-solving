// 875. Koko Eating Bananas
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // O(N * log(K))
        int N = piles.size();
        long long Max = *max_element(piles.begin(), piles.end());
        long long lo = 1, hi = Max;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long sum = count(piles, mid);
            if (sum > h)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
    
    inline long long count(vector<int>& piles, int k) {
        long long sum = 0;
        for (auto pile : piles) {
            long long div = pile / k;
            long long mod = pile % k;
            sum += div + (mod == 0 ? 0 : 1);
        }
        return sum;
    }
};

int main(void) {
    Solution s;
}
