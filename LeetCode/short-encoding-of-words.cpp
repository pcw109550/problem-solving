#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // O(L * N * log(N))
        int N = words.size();
        int result = 0;
        for (int i = 0; i < N; i++)
            reverse(words[i].begin(), words[i].end());
        sort(words.begin(), words.end());
        string curword = words[0];
        for (int i = 1; i < N; i++) {
            if (words[i].substr(0, curword.size()) == curword)
                curword = words[i];
            else {
                result += curword.size() + 1;
                curword = words[i];
            }
        }
        result += curword.size() + 1;
        return result;
    }
};