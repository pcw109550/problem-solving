// 171. Excel Sheet Column Number
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        // O(N)
        int result = 0;
        int N = columnTitle.size();
        for (auto c : columnTitle) {
            result *= 26;
            result += c - 'A' + 1;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
