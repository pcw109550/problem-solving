#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // O(N * log(N))
        int N = properties.size();
        int result = 0;
        unordered_map<int, int> M;
        sort(properties.begin(), properties.end());
        vector<int> D(N, 0); D[N - 1] = properties[N - 1][1];
        vector<int> uniq;
        for (int i = 0; i < N; i++)
            if (uniq.empty() || uniq.back() != properties[i][0]) {
                M[properties[i][0]] = uniq.size();
                uniq.push_back(i);
            }
        for (int i = N - 2; i >= 0; i--) 
            D[i] = max(D[i + 1], properties[i][1]);
        for (int i = 0; i < N - 1; i++) {
            if (M[properties[i][0]] + 1 >= uniq.size())
                continue;
            int next_idx = uniq[M[properties[i][0]] + 1];
            if (properties[i][1] < D[next_idx])
                result++;            
        }
        return result;
    }
};