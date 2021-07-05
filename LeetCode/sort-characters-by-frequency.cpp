// 451. Sort Characters By Frequency
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            // O(N + K * log(K))
            string result;
            unordered_map<char, int> M;
            for (auto c : s)
                M[c]++;
            vector<pair<int, int> > temp;
            for (auto it : M)
                temp.push_back({it.second, it.first});
            sort(temp.begin(), temp.end());
            for (int i = temp.size() - 1; i >= 0; i--) {
                for (int k = 0; k < temp[i].first; k++)
                    result.push_back(temp[i].second);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}