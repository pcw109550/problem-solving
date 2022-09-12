#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // O(1)
        int result = ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
        return result;
    }
};