// 1647. Minimum Deletions to Make Character Frequencies Unique
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        // O(N)
        int result = 0;
        unordered_map<char, int> M;
        for (auto c : s)
            M[c]++;
        vector<int> v;
        for (auto it : M)
            v.push_back(it.second);
        sort(v.begin(), v.end());
        for (int i = v.size() - 1; i > 0; i--) {
            if (v[i] <= v[i - 1]) {
                int temp = (v[i] - 1 >= 0 ? v[i] - 1 : 0);
                result += v[i - 1] - temp;
                v[i - 1] = temp;
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}