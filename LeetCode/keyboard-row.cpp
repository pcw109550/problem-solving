// 500. Keyboard Row
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // O(N)
        vector<string> s = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> M;
        for (int i = 0; i < 3; i++)
            for (auto c : s[i])
                M[c] = i;
        vector<string> result;
        for (auto word : words) {
            unordered_set<int> S;
            for (auto c : word)
                S.insert(M[tolower(c)]);
            if (S.size() == 1)
                result.push_back(word);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
