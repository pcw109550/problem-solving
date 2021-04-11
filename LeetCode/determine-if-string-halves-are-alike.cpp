// 1704. Determine if String Halves Are Alike
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
    std::unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u',
                                     'A', 'E', 'I', 'O', 'U'};
    public:
        bool halvesAreAlike(std::string s) {
            // O(N)
            int N = s.size();
            int c1 = count(s, 0, N / 2 - 1);
            int c2 = count(s, N / 2, N - 1);
            return c1 == c2;
        }
    
        int count(std::string &s, int start, int end) {
            int result;
            for (int i = start; i <= end; i++)
                if (vowels.count(s[i]))
                    result++;
            return result;
        }
        
};

int main(void) {
    Solution s;
}