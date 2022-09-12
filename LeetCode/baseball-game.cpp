#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        // O(N)
        int result = 0;
        int N = ops.size();
        stack<int> S;
        for (auto it : ops) {
            if (it[0] == '+') {
                int a = S.top(); S.pop();
                int b = S.top(); S.push(a);
                S.push(a + b);
            } else if (it[0] == 'D') {
                int a = S.top();
                S.push(a * 2);
            } else if (it[0] == 'C') 
                S.pop();
            else {
                int x = stoi(it);
                S.push(x);
            }
        }
        while (!S.empty()) {
            result += S.top();
            S.pop();
        }
        return result;
    }
};