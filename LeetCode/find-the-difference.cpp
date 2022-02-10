// 389. Find the Difference
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        // O(N)
        unordered_map<char, int> M;
        for (auto c : t)
            M[c]++;
        for (auto c : s) {
            M[c]--;
            if (M[c] == 0)
                M.erase(c);
        }
        char result = M.begin()->first;
        return result;
    }
};

int main(void) {
    Solution s;
}
