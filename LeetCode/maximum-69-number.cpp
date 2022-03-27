// 1323. Maximum 69 Number
#include <iostream>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        // O(log(N))
        int temp = num;
        int target = 0;
        int cur = 1;
        while (temp > 0) {
            if (temp % 10 == 6)
                target = cur;
            cur *= 10;
            temp /= 10;
        }
        num += target * 3;
        return num;
    }
};

int main(void) {
    Solution s;
}
