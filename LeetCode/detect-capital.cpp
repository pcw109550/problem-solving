// 520. Detect Capital
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        // O(N)
        int cnt = 0, N = word.size();
        for (auto w : word)
            if (w == toupper(w))
                cnt++;
        if (cnt == N || cnt == 0)
            return true;
        if (cnt == 1 && word[0] == toupper(word[0]))
            return true;
        return false;
    }
};

int main(void) {
    Solution s;
}
