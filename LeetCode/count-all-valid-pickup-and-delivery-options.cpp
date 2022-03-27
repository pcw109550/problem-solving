// 1359. Count All Valid Pickup and Delivery Options
#include <iostream>
#include <vector>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int countOrders(int n) {
        // O(N)
        long long result = 1;
        // (2 * n)! / (2 ** n)
        for (int i = 2 * n; i >= 1; i--)
            result = (result * (i % 2 ? i : i / 2)) % FIELD;
        return result;
    }
};

int main(void) {
    Solution s;
}
