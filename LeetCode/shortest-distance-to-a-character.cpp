// 821. Shortest Distance to a Character
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define MAX 1 << 30

class Solution {
    public:
        std::vector<int> shortestToChar(std::string s, char c) {
            // O(N)
            int N = s.size();
            std::vector<int> result(N, MAX);
            int start = -1;
            for (int i = 0; i < N; i++) {
                if (s[i] == c) {
                    result[i] = 0;
                    start = 1;
                } else if (start != -1) {
                    result[i] = std::min(result[i], start);
                    start++;
                }
            }
            start = -1;
            for (int i = N - 1; i >= 0; i--) {
                if (s[i] == c) {
                    result[i] = 0;
                    start = 1;
                } else if (start != -1) {
                    result[i] = std::min(result[i], start);
                    start++;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}