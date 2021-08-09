// 415. Add Strings
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        // O(N)
        string result;
        int M = num1.size(), N = num2.size();
        if (M < N)
            swap(num1, num2);
        auto it1 = num1.rbegin(), it2 = num2.rbegin();
        bool carry = false;
        while (it1 != num1.rend()) {
            int a = *it1 - '0', b = 0;
            it1++;
            if (it2 != num2.rend()) {
                b = *it2 - '0';
                it2++;   
            }
            result.push_back('0' + (carry + a + b) % 10);
            carry = a + b + carry >= 10;
        }
        if (carry)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(void) {
    Solution s;
}