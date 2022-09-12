#include <algorithm>
#include <iostream>
#include <cctype>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        // O(M * log(M))
        text[0] = tolower(text[0]);
        string result;
        vector<pair<int, int> > D;
        text.push_back(' ');
        int N = text.size();
        string token; int cnt = 0;
        vector<string> tokens;
        for (int i = 0; i < N; i++) {
            if (text[i] == ' ') {
                D.push_back({token.size(), cnt});
                tokens.push_back(token);
                cnt++;
                token.clear();
                continue;
            } 
            token.push_back(text[i]);
        }
        sort(D.begin(), D.end());
        for (int i = 0; i < cnt; i++) {
            result += tokens[D[i].second];
            result.push_back(' ');
        }
        result.pop_back();
        result[0] = toupper(result[0]);
        return result;
    }
};