// 1750. Minimum Length of String After Deleting Similar Ends
#include <iostream>
#include <string>

class Solution {
    public:
        int minimumLength(std::string s) {
            // O(N)
            int N = s.size();
            int start = 0, end = N - 1;
            while (s[start] == s[end] && start < end) {
                char c = s[start];
                while (start < end && s[start] == c)
                    start++;
                if (start == end && s[start] == c)
                    return 0;
                while (start < end && s[end] == c)
                    end--;
            }
            std::cout << std::endl;
            int result = end - start + 1;
            return result;
        }
};

int main(void) {
    Solution s;
}