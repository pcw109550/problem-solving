#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // O(N)
        string x, y;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            if (s[i] != '#')
                x.push_back(s[i]);
            else if (!x.empty())
                x.pop_back();
        }
        int M = t.size();
        for (int i = 0; i < M; i++) {
            if (t[i] != '#')
                y.push_back(t[i]);
            else if (!y.empty())
                y.pop_back();
        }
        return x == y;
    }
};