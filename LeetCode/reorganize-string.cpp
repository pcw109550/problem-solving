// 767. Reorganize String
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        // O(N)   
        string result;
        int N = s.size();
        unordered_map<int, int> M;
        for (int i = 0; i < N; i++) {
            M[s[i]]++;
            if (M[s[i]] > N / 2 + N % 2)
                return result;
        }
        vector<pair<int, int> > accs;
        for (auto it : M)
            accs.push_back({it.second, it.first});
        sort(accs.begin(), accs.end(), greater<pair<int, int> > ());
        result = string (N, '0');
        int probe = 0;
        for (auto it : accs) {
            for (int i = 0; i < it.first; i++) {
                if (result[probe] != '0')
                    probe++;
                result[probe] = it.second;
                probe = (probe + 2) % N;
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
