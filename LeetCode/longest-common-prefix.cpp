// 14. Longest Common Prefix
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            // O(N)
            if (strs.size() == 0)
                return std::string ("");
            std::string result ("");
            int idx = 0;
            bool flag = true;
            char current;
            while (flag) {
                flag = true;
                for (int i = 0; i < strs.size(); i++) {
                    if (strs[i].size() <= idx)
                        return result;
                    if (i == 0) {
                        current = strs[i][idx];
                        continue;
                    }
                    if (current != strs[i][idx]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    result += current;
                idx++;
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<std::string> strs {{"flower", "flow", "flight"}};
    auto result = s.longestCommonPrefix(strs);
    std::cout << result << '\n';
}