#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        // O(N)
        vector<char> C;
        vector<int> cnts;
        examine(C, cnts, s);
        int result = 0;
        for (auto word : words) {
            vector<char> Ccur;
            vector<int> cntscur;
            examine(Ccur, cntscur, word);
            if (Ccur.size() != C.size())
                continue;
            int N = Ccur.size();
            bool found = true;
            for (int i = 0; i < N; i++) {
                if (Ccur[i] != C[i]) {
                    found = false;
                    break;
                }
                int a = cnts[i], b = cntscur[i];
                if (a == b)
                    continue;
                if (a > b && a >= 3)
                    continue;
                found = false;
                break;
            }
            if (found)
                result++;
        }
        return result;
    }
    
    void examine(vector<char> &C, vector<int> &cnts, string &s) {
        for (auto it : s) {
            if (C.empty() || C.back() != it) {
                C.push_back(it);
                cnts.push_back(1);
            } else
                cnts[cnts.size() - 1]++;        
        }
    }
};