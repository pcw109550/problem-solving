#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        // O(log(N))
        string result;
        vector<int> temp(64, 0);
        bool rev = false;
        int cnt = 0;
        while (n > 0) {
            if (n & 1) {
                if (!rev)
                    temp[cnt]++;
                else {
                    temp[cnt]++;
                    temp[cnt + 1]++;
                }
            }
            rev = !rev;
            n >>= 1;
            cnt++;
        }
        for (int i = 0; i < cnt + 2; i++) {
            if (temp[i] == 2) {
                if (temp[i + 1] == 1)
                    temp[i] = temp[i + 1] = 0;
                else if (temp[i + 1] == 0) {
                    temp[i] = 0;
                    temp[i + 1] = 1;
                    temp[i + 2]++;
                }
            }
            result.push_back(temp[i] + '0');
        }
        while (result.back() == '0')
            result.pop_back();
        reverse(result.begin(), result.end());
        if (result.empty())
            result.push_back('0');
        return result;
    }
};