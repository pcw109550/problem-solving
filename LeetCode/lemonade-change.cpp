#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // O(N)
        int N = bills.size();
        unordered_map<int, int> M;
        for (int i = 0; i < N; i++) {
            int bill = bills[i];
            if (bill == 5)
                M[5]++;
            else if (bill == 10) {
                if (M[5] == 0)
                    return false;
                M[5]--; M[10]++;
            } else if (bill == 20) {
                if (M[5] >= 1 && M[10] >= 1) {
                    M[5]--; M[10]--;
                } else if (M[5] >= 3) {
                    M[5] -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};