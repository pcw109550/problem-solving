#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        // O(N)
        int N = rungs.size();
        int result = 0;
        for (int i = 0; i < N; i++) {
            int delta = rungs[i] - (i >= 1 ? rungs[i - 1] : 0);
            result += (delta - 1) / dist;
        }
        return result;
    }
};