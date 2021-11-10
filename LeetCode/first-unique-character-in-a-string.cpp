// 387. First Unique Character in a String
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // O(N)
        vector<pair<int, char> > order;
        unordered_map<char, int> M;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            if (!M.count(s[i]))
                order.push_back({i, s[i]});
            M[s[i]]++;
        }
        for (auto p : order)
            if (M[p.second] == 1)
                return p.first;
        return -1;
    }
};

int main(void) {
    Solution s;
}