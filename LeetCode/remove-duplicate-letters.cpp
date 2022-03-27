// 316. Remove Duplicate Letters
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // O(N)
        string result;
        unordered_map<char, vector<int> > M;
        int N = s.size();
        for (int i = 0; i < N; i++)
            M[s[i]].push_back(i);
        vector<int> ps (26, 0);
        stack<char> S;
        unordered_set<int> T;
        for (int i = 0; i < N; i++) {
            if (S.empty() || (S.top() < s[i] && !T.count(s[i]))) {
                S.push(s[i]);  
                T.insert(s[i]);
                ps[s[i] - 'a']++;
            } else {
                if (T.count(s[i])) {
                    ps[s[i] - 'a']++;
                    continue;
                }
                while (!S.empty() && S.top() >= s[i] && ps[S.top() - 'a'] < M[S.top()].size()) {
                    T.erase(S.top());
                    S.pop();
                }
                if (!T.count(s[i])) {
                    S.push(s[i]);
                    T.insert(s[i]);
                    ps[s[i] - 'a']++;
                }
            }
        }
        while (!S.empty()) {
            result.push_back(S.top()); S.pop();
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
}; 

int main(void) {
    Solution s;
}
