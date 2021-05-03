// 299. Bulls and Cows
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        std::string getHint(std::string secret, std::string guess) {
            // O(N)
            std::string result;
            int x = 0, y = 0;
            int N = secret.size();
            std::unordered_map<char, int> a, b;
            for (int i = 0; i < N; i++) {
                if (secret[i] == guess[i]) {
                    x++;
                    continue;
                }
                a[secret[i]]++;
                b[guess[i]]++;
            }
            for (auto it: a) {
                if (b.count(it.first))
                    y += std::min(it.second, b[it.first]);
            }
            result += std::to_string(x);
            result += std::string(1, 'A');
            result += std::to_string(y);
            result += std::string(1, 'B');
            return result;
        }
};

int main(void) {
    Solution s;
}