// 1922. Count Good Numbers
#include <iostream>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int countGoodNumbers(long long n) {
        // log(N)
        long long num_4 = n / 2;
        long long num_5 = n - n / 2;
        long long result = 1;
        result = result * pow(4, num_4) % FIELD;
        result = result * pow(5, num_5) % FIELD;
        return result;
    }
    
    long long pow(long long base, long long exp) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp & 1)
                result = result * base % FIELD; 
            exp >>= 1;
            base = base * base % FIELD;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
