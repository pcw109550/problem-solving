#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // O(M * N)
        int N = strs.size(), M = strs[0].size();
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            char prev = '\0';
            for (int j = 0; j < N; j++) {
                if (prev > strs[j][i]) {
                    cnt++;
                    break;
                }
                prev = strs[j][i];
            }
        }
        return cnt;
    }
};