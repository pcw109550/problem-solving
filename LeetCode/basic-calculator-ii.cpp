// 227. Basic Calculator II
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        // O(N)
        int result = 0;
        int N = s.size();
        vector<char> opt;
        vector<int> val;
        string v;
        for (int i = 0; i < N; i++) {
            char c = s[i];
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                val.push_back(stoi(v));
                opt.push_back(c);
                v.clear();
            } else
                v.push_back(c);
        }
        val.push_back(stoi(v));
        int cur = val.front();
        for (int i = 0; i < opt.size(); i++) {
            char c = opt[i];
            if (c == '+' || c == '-') {
                result += cur;
                cur = (c == '-' ? -1 : 1) * val[i + 1];
            } else if (c == '*') {
                cur = cur * val[i + 1];
            } else if (c == '/') {
                cur = cur / val[i + 1];
            }
        }
        result += cur;
        return result;
    }
};

int main(void) {
    Solution s;
}