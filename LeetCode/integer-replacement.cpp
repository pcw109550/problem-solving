// 397. Integer Replacement
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
    unordered_map<long long, int> cache;
    public:
        int integerReplacement(int n) {
            // O(log(N))
            cache[1] = 0;
            return recurse(n);
        }
    
        int recurse(long long n) {
            if (n <= 0)
                return INT_MIN;
            if (cache.count(n))
                return cache[n];            
            if (n % 2 == 0)
                cache[n] = 1 + recurse(n / 2);
            else
                cache[n] = 1 + min(recurse(n + 1), recurse(n - 1));
            return cache[n];
        }
};

int main(void) {
    Solution s;
}