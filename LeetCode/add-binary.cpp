// 67. Add Binary
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // O(max(M + N))
        string result;
        int M = a.size(), N = b.size();
        bool carry = false;
        for (int i = 0; i < max(M, N); i++) {
            int num = carry;
            num += i < M ? a[M - i - 1] - '0' : 0;
            num += i < N ? b[N - i - 1] - '0' : 0;
            carry = num >= 2 ? true : false;
            result.push_back('0' + num % 2);
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