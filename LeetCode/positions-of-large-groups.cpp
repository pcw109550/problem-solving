#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        // O(N)
        vector<vector<int> > result;
        char cur = '\0';
        int start = -1, cnt = 1;
        s.push_back('\0');
        int N = s.size();
        for (int i = 0; i < N; i++) {
            char t = s[i];
            if (t != cur) {
                if (cnt >= 3)
                    result.push_back(vector<int> {start, start + cnt - 1});
                start = i;
                cnt = 1;
                cur = t;
            } else
                cnt++;
        }
        return result;
    }
};