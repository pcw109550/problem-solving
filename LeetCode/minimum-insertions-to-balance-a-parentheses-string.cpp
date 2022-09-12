#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        // O(N)
        int result = 0;
        int N = s.size();
        vector<int> S;
        int i = 0;
        while (i < N) {
            if (s[i] == '(') {
                S.push_back(i);
                i++;
            } else if (s[i] == ')') {
                if (i + 1 >= N || s[i + 1] != ')') {
                    result++;
                    if (S.empty())
                        result++;
                    else
                        S.pop_back();
                    i += 1;
                } else if (s[i + 1] == ')') {
                    if (S.empty())
                        result++;
                    else
                        S.pop_back();
                    i += 2;
                }
            }
        }
        result += S.size() * 2;
        return result;
    }
};