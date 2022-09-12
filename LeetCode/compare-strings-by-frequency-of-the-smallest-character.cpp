#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // O(N * log(N) + M * log(N))
        vector<int> result;
        vector<int> prep;
        for (auto word : words)
            prep.push_back(f(word));
        sort(prep.begin(), prep.end());
        for (auto query : queries) {
            int K = f(query);
            int delta = prep.end() - upper_bound(prep.begin(), prep.end(), K);
            result.push_back(delta);
        }
        return result;
    }
    
    int f(string &word) {
        map<char, int> M;
        for (auto w : word)
            M[w]++;
        return M.begin()->second;
    }
};