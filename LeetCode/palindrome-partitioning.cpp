// 131. Palindrome Partitioning
#include <vector>
#include <iostream>
#include <string>

class Solution {
    public:
        std::vector<std::vector<std::string> > result;
        std::string input_s;
        std::vector<std::vector<std::string> > partition(std::string s) {
            // Time O(N * 2 ** N) Space O(N)
            input_s = s;
            std::vector<std::string> temp;
            gen_partition(temp, 0);
            return result;
        }
    
        void gen_partition(std::vector<std::string> temp, int idx) {
            if (idx == input_s.size()) {
                result.push_back(temp);
                return;
            }
            for (int i = 1; i <= input_s.size() - idx; i++) {
                auto substr = input_s.substr(idx, i);
                if (is_palindrome(substr)) {
                    temp.push_back(substr);
                    gen_partition(temp, idx + i);
                    temp.pop_back();
                }
            }
        }

        inline bool is_palindrome(std::string &s) {
            for (int i = 0; i < s.size() / 2; i++)
                if (s[i] != s[s.size() - i - 1])
                    return false;
            return true;
        }
};

int main(void) {
    Solution s;
}