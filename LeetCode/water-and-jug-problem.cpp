#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        // O(log(N))
        int a = jug1Capacity, b = jug2Capacity, c = targetCapacity;
        if (a + b < c)
            return false;
        if (a == b)
            return a == c || 2 * a == c;
        int gcd = __gcd(a, b);
        return c % gcd == 0;
    }
};