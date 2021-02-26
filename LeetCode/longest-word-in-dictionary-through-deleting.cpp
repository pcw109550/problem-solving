// 524. Longest Word in Dictionary through Deleting
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::string findLongestWord(std::string s, std::vector<std::string>& d) {
            // O(N)
            std::string result;
            for (auto str: d)
                if (compare(s, str)) {
                    if (str.size() > result.size())
                        result = str;
                    else if (str.size() == result.size() && result > str)
                        result = str;
                }
            return result;
        }
    
        inline bool compare(std::string &s, std::string &c) {
            int i = 0, j = 0;
            while (i < s.size() && j < c.size()) {
                if (s[i] == c[j])
                    j++;
                i++;            
            }
            return j == c.size();
        }
};

int main(void) {
    Solution s;
}