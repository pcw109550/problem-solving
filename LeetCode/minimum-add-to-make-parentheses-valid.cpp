#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        // O(N)
        int result = 0;
        stack<int> S;
        for (auto c : s) {
            if (S.empty()) {
                S.push(c);
            } else {
                if (S.top() == '(' && c == ')') {
                    S.pop();
                    continue;
                }
                S.push(c);
            }
        }
        result = S.size();
        return result;
    }
};