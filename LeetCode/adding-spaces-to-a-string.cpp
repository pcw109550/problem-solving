#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // O(M + N)
        string result;
        int N = s.size();
        int pos = 0;
        for (int i = 0; i < N; i++) {
            if (pos < spaces.size() && spaces[pos] == i) {
                result.push_back(' ');
                pos++;
            }
            result.push_back(s[i]);
        }
        return result;
    }
};