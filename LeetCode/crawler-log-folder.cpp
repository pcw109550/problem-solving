#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        // O(N)
        stack<string> S;
        for (auto log : logs) {
            if (log[0] == '.' && log[1] == '/')
                continue;
            if (log[0] == '.' && log[1] == '.') {
                if (!S.empty())
                    S.pop();
                continue;
            }
            S.push(log);
        }        
        return S.size();
    }
};