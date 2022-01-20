// 1291. Sequential Digits
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // O(log(N))
        vector<int> result;
        vector<long long> digits {12, 23, 34, 45, 56, 67, 78, 89};
        vector<long long> nextdigits;
        while (true) {
            nextdigits.clear();
            for (auto digit : digits) {
                if (low <= digit && digit <= high)
                    result.push_back(digit);
                if (digit % 10 + 1 <= 9)
                    nextdigits.push_back(digit * 10 + (digit % 10) + 1);
            }
            if (nextdigits.empty())
                break;
            digits = nextdigits;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
