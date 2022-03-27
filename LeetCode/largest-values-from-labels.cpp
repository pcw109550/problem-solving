// 1090. Largest Values From Labels
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        // O(N * log(N))
        int result = 0;
        vector<pair<int, int> > D;
        int N = values.size();
        for (int i = 0; i < N; i++)
            D.push_back({values[i], labels[i]});
        sort(D.begin(), D.end(), greater<pair<int, int> > ());
        unordered_map<int, int> M;
        int inserted = 0;
        for (int i = 0; i < N; i++) {
            auto it = D[i];
            int value = it.first, label = it.second;
            if (M[label] < useLimit && inserted < numWanted) {
                M[label]++;
                result += value;
                inserted++;
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
