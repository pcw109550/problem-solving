// 1247. Minimum Swaps to Make Strings Equal
#include <iostream>
#include <string>

class Solution {
    public:
        int minimumSwap(std::string s1, std::string s2) {
            if (s1.size() != s2.size())
                return -1;
            int diff = 0, result = 0;
            int o[2] = {};
            for (int i = 0; i < s1.size(); i++)
                if (s1[i] != s2[i]) {
                    o[s1[i] > s2[i]]++;
                    diff++;
                }
            if (diff % 2 != 0)
                return -1;
            result += o[0] / 2;
            result += o[1] / 2;
            if (o[0] % 2 == 1)
                result += 2;
            return result;
        }
};

int main(void) {
    Solution s;
}