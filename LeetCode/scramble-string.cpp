#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
    string s1, s2;
    int N;
    vector<vector<vector<int> > > cache;
public:
    bool isScramble(string _s1, string _s2) {
        // O()
        s1 = _s1, s2 = _s2;
        N = s1.size();
        // 2: success, 1: fail, 0: not visited
        cache = vector<vector<vector<int> > >(2, vector<vector<int> >(N, vector<int> (N)));
        return traversal(0, N, false);
    }
    
    bool traversal(int s, int e, bool swapped) {
        if (cache[swapped][s][e - 1] >= 1)
            return cache[swapped][s][e - 1] == 2;
        int n = e - s;
        if (n == 1 && s1[s] == s2[s]) {
            cache[swapped][s][e - 1] = 2;
            return true;
        }
        vector<int> o1(26), o2(26);
        for (int i = s; i < e; i++) {
            o1[s1[i] - 'a']++;
            o2[s2[i] - 'a']++;
        }
        if (o1 != o2) {
            cache[swapped][s][e - 1] == 1;
            return false;
        }
        for (int i = s; i < e - 1; i++) {
            bool l = traversal(s, i + 1, swapped);
            if (!l)
                continue;
            bool r = traversal(i + 1, e, swapped);
            if (!r)
                continue;
            if (l && r) {
                cache[swapped][s][e - 1] = 2;
                return true;
            }
        }
        reverse(s1.begin() + s, s1.begin() + e);
        for (int i = s; i < e - 1; i++) {
            bool l = traversal(s, i + 1, !swapped);
            if (!l)
                continue;
            bool r = traversal(i + 1, e, !swapped);
            if (!r)
                continue;
            if (l && r) {
                reverse(s1.begin() + s, s1.begin() + e);
                cache[!swapped][s][e - 1] = 2;
                return true;
            }
        }
        reverse(s1.begin() + s, s1.begin() + e);
        cache[swapped][s][e - 1] = 1;
        return false;
    }
};