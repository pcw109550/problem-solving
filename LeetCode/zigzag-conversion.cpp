#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // O(N)
        if (numRows == 1)
            return s;
        string result;
        int N = s.size();
        int i = 0;
        int D = 2 * (numRows - 1);
        while (i < N) {
            result.push_back(s[i]);
            i += D;
        }
        int delta = D - 2;
        for (int j = 1; j < numRows - 1; j++) {
            i = j;
            while (i < N) {
                result.push_back(s[i]);
                int cand = i + delta;
                if (cand < N)
                    result.push_back(s[cand]);
                i += D;
            } 
            delta -= 2;
        }
        i = numRows - 1;
        while (i < N) {
            result.push_back(s[i]);
            i += D;
        }
        return result;
    }
};