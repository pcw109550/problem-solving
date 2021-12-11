// 878. Nth Magical Number
#include <algorithm>
#include <iostream>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        // O(log(max(a, b)) + a + b)
        long long result = 0;
        // O(log(max(a, b)))
        long long gcd = __gcd(a, b);
        long long lcm = a * b / gcd;
        long long period = lcm / a + lcm / b - 1;
        long long num = n / period;
        long long delta = n % period;
        long long start = num * lcm;
        if (delta == 0) {
            result = start % FIELD;
            return result;
        }
        long long cur = start;
        long long x = 1, y = 1;
        // O(a + b)
        for (int i = 0; i < delta; i++) {
            if (a * x < b * y) {
                cur = start + a * x;
                x++;
            } else {
                cur = start + b * y;
                y++;
            }
        }
        result = cur;
        result %= FIELD;
        return result;
    }
};

int main(void) {
    Solution s;
}