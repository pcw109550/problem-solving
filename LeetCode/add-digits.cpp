// 258. Add Digits
#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // O(1)
        int result;
        while (num >= 10) {
            int next = 0;
            while (num > 0) {
                next += num % 10;
                num /= 10;
            }
            num = next;
        }
        result = num;
        return result;
    }
};

int main(void) {
    Solution s;
}