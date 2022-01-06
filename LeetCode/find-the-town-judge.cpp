// 997. Find the Town Judge
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // O(N + n)
        int result = -1;
        int N = trust.size();
        unordered_map<int, unordered_set<int> > M;
        unordered_set<int> S;
        for (int i = 0; i < N; i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            M[b].insert(a);
            S.insert(a);
        }
        for (int i = 1; i <= n; i++)
            if (M[i].size() == n - 1 && !M[i].count(i) && !S.count(i)) {
                if (result != -1)
                    return -1;
                result = i;
            }
        return result;
    }
};

int main(void) {
    Solution s;
}