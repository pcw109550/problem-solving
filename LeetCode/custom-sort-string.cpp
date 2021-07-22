// 791. Custom Sort String
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<char, int> M;
public:
    string customSortString(string order, string str) {
        // O(N * log(N))
        string result;
        for (int i = 0; i < order.size(); i++)
            M[order[i]] = i;
        sort(str.begin(), str.end(), [=](const auto& lhs, const auto& rhs) {
            int a = M.count(lhs) ? M[lhs] : -1;
            int b = M.count(rhs) ? M[rhs] : -1;
            return a < b;
        });
        return result = str;
    }
};

int main(void) {
    Solution s;
}