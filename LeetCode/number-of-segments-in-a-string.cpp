// 434. Number of Segments in a String
#include <iostream>
#include <string>

class Solution {
    public:
        int countSegments(std::string s) {
            // O(N)
            int result = 0;
            bool in_token = false;
            for (auto it : s)
                if (it != ' ' && !in_token) {
                    in_token = true;
                    result++;
                } else if (it == ' ' && in_token){
                    in_token = false;
                }
            return result;
        }
};

int main(void) {
    Solution s;
}