#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        // O(N)
        vector<int> result;
        for (int i = 1; i <= n / 2; i++) {
            result.push_back(i);
            result.push_back(-i);
        }
        if (n % 2)
            result.push_back(0);
        return result;
    }
};