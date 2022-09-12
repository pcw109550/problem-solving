#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string, vector<char> > M;
    bool result;
    vector<string> new_bases;
    unordered_set<string> seen;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // O(N ** (K + 1))
        result = false;
        for (auto a : allowed)
            M[a.substr(0, 2)].push_back(a[2]);
        gen_new_bases(bottom, string(), 0);
        return result;
    }
    
    void gen_new_bases(string base, string cur, int idx) {
        if (result)
            return;
        if (base.size() == 1) {
            result = true;
            return;
        }
        if (cur.size() == base.size() - 1 && !seen.count(cur)) {
            seen.insert(cur);
            gen_new_bases(cur, string(), 0);            
            return;
        }
        auto cands = M[base.substr(idx, 2)];
        for (auto cand : cands) {
            cur.push_back(cand);
            gen_new_bases(base, cur, idx + 1);
            cur.pop_back();
        }
    }
};