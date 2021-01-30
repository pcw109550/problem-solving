// 1694. Reformat Phone Number
#include <iostream>
#include <string>

class Solution {
    public:
        std::string reformatNumber(std::string number) {
            // O(N)
            std::string temp, result;
            for (auto it : number) {
                if ('0' <= it && it <= '9')
                    temp += std::string(1, it);
            }
            int k = 0;
            while (k + 4 < temp.size()) {
                result += temp.substr(k, 3);
                result += std::string(1, '-');
                k += 3;
            }
            if (temp.size() - k <= 3)
                result += temp.substr(k, temp.size() - k);
            else {
                result += temp.substr(k, 2);
                result += std::string(1, '-');
                result += temp.substr(k + 2, 2);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}