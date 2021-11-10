// 1816. Truncate Sentence
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        // O(N)
        s.push_back(' ');
        int N = s.size();
        int idx = 0, pos = N - 1;
        for (int i = 0; i < N; i++) {
            if (s[i] == ' ') {
                idx++;
                pos = i;
                if (idx == k)
                    break;
            }
        }
        auto result = s.substr(0, pos);
        return result;
    }
};

int main(void) {
    Solution s;
}