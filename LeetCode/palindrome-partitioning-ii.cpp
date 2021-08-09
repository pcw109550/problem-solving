// 132. Palindrome Partitioning II
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    vector<int> M;
    int N;
    unordered_map<int, unordered_set<int> > occ;
public:
    int minCut(string s) {
        // O(N ** 2)
        N = s.size();
        M = vector<int> (N, -1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++)
                if (c(s, j, i)) {
                    occ[i].insert(j);
                    if (j == 0)
                        M[i] = 0;
                    else if (M[i] == -1)
                        M[i] = M[j - 1] + 1;
                    else
                        M[i] = min(M[i], M[j - 1] + 1);
                }
        }
        return M[N - 1];
    }
    
    inline bool c(string &s, int start, int end) {
        if (s[start] != s[end])
            return false;
        if (start + 1 <= end - 1 && !occ[end - 1].count(start + 1))
            return false;
        return true;
    }
};

class Solution2 {
    vector<int> M;
    int N;
public:
    int minCut(string s) {
        // O(N ** 3)
        N = s.size();
        M = vector<int> (N, -1);
        for (int i = 0; i < N; i++) {
            if (c(s, 0, i)) {
                M[i] = 0;
                continue;
            }
            for (int j = 1; j <= i; j++)
                if (c(s, j, i)) {
                    if (M[i] == -1)
                        M[i] = M[j - 1] + 1;
                    else
                        M[i] = min(M[i], M[j - 1] + 1);
                }
        }
        return M[N - 1];
    }
    
    inline bool c(string &s, int start, int end) {
        for (int i = start; i <= start + (end - start) / 2; i++)
            if (s[i] != s[end - (i - start)])
                return false;
        return true;
    }
};

int main(void) {
    Solution s;
}