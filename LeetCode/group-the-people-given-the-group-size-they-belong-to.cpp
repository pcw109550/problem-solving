// 1282. Group the People Given the Group Size They Belong To
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // O(N)
        vector<vector<int> > result;
        unordered_map<int, vector<int> > M;
        int N = groupSizes.size();
        for (int i = 0; i < N; i++) {
            M[groupSizes[i]].push_back(i);
            if (M[groupSizes[i]].size() == groupSizes[i]) {
                result.push_back(M[groupSizes[i]]);
                M[groupSizes[i]].clear();
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
