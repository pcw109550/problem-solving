// 1844. Replace All Digits with Characters
#include <string>

class Solution {
    public:
        std::string replaceDigits(std::string s) {
            int N = s.size();
            for (int i = 0; i < N / 2; i++)
                s[2 * i + 1] = s[2 * i + 1] - '0' + s[2 * i];
            return s;
        }
};

int main(void) {
    Solution s;
}