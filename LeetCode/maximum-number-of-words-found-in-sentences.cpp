#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        // O(N)
        int result = 0;
        int N = sentences.size();
        for (auto sentence : sentences)
            result = max(result, count(sentence));
        return result;
    }
    
    inline int count(string &s) {
        int cnt = 1;
        for (auto it : s)
            if (it == ' ')
                cnt++;
        return cnt;
    }
};