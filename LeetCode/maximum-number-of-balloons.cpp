// 1189. Maximum Number of Balloons
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // O(N)
        int result = 0;
        int N = text.size();
        unordered_map<char, int> M;
        for (int i = 0; i < N; i++)
            M[text[i]]++;
        vector<int> D;
        if (M.count('b'))
            D.push_back(M['b']);
        else
            return 0;
        if (M.count('a'))
            D.push_back(M['a']);
        else
            return 0;
        if (M.count('n'))
            D.push_back(M['n']);
        else
            return 0;
        if (M.count('l'))
            D.push_back(M['l'] / 2);
        else
            return 0;
        if (M.count('o'))
            D.push_back(M['o'] / 2);
        else
            return 0;
        if (D.size() > 0)
            result = *min_element(D.begin(), D.end());
        return result;
    }
};

int main(void) {
    Solution s;
}