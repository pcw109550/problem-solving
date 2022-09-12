#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        // O(log(N))
        if (num == 0)
            return string (1, '0');
        string result;
        bool neg = num < 0;
        if (neg)
            num = -num;
        while (num > 0) {
            result.push_back(num % 7 + '0');
            num /= 7;
        }
        if (neg)
            result.push_back('-');
        reverse(result.begin(), result.end());
        return result;
    }
};