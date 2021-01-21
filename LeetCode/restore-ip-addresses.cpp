// 93. Restore IP Addresses
#include <iostream>
#include <vector>
#include <string>

class Solution {
    std::vector<std::string> result;
    std::string str;
    int N;
    public:
        std::vector<std::string> restoreIpAddresses(std::string s) {
            // O(N ** 3)
            str = s;
            N = str.size();
            backtrack(0, 0, std::string());
            return result;
        }
    
        void backtrack(int idx, int stage, std::string temp) {
            if (4 - stage > N - idx)
                return;
            if (stage == 4) {
                if (idx == N)
                    result.push_back(temp);
                return;
            }
            for (int i = 1; i <= 3 && idx + i <= N; i++)
                if (is_valid(idx, i)) {
                    std::string next(temp);
                    if (idx != 0)
                        next += ".";
                    next += str.substr(idx, i);
                    backtrack(idx + i, stage + 1, next);
                }
        }
    
        bool is_valid(int a, int b) {
            if (b == 1)
                return true;
            else {
                if (str[a] == '0')
                    return false;
            }
            int translate = std::stoi(str.substr(a, b));
            if (translate < 0 || translate > 255)
                return false;
            return true;
        }
};

int main(void) {
    Solution s;
}