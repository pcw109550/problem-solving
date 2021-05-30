// 38. Count and Say
#include <iostream>
#include <string>

class Solution {
    public:
        std::string countAndSay(int n) {
            // O(N ** 2)
            std::string result = "1", temp;
            for (int i = 0; i < n - 1; i++) {
                char cur = '\0';
                int cnt = 0;
                for (auto c : result) {
                    if (cur == '\0' || cur == c)
                        cnt++;
                    else {
                        temp.push_back(cnt + '0');
                        temp.push_back(cur);
                        cnt = 1;
                    }
                    cur = c;
                }
                temp.push_back(cnt + '0');
                temp.push_back(cur);
                result = temp;
                temp.resize(0);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}