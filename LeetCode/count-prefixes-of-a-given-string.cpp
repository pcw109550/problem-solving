#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        // O(N * M)
        int result = 0;
        int N = words.size(), M = s.size();
        for (auto word : words) {
            int cnt = 0;
            for (int i = 0; i < min(M, (int)word.size()); i++)
                cnt += word[i] == s[i];
            if (cnt == word.size())
                result++;
        }
        return result;
    }
};