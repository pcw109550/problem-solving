// 13. Roman to Integer
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
    public:
        int romanToInt(std::string s) {
            // O(N)
            std::unordered_set<char> S;
            int result = 0;
            int N = s.size();
            for (int i = N - 1; i >= 0; i--) {
                switch (s[i]) {
                    case 'I':
                        result = S.count('V') || S.count('X') ? result - 1 : result + 1;
                        break;
                    case 'V':
                        result += 5;
                        break;
                    case 'X':
                        result = S.count('L') || S.count('C') ? result - 10 : result + 10;
                        break;
                    case 'L':
                        result += 50;
                        break;
                    case 'C':
                        result = S.count('D') || S.count('M') ? result - 100 : result + 100;
                        break;
                    case 'D':
                        result += 500;
                        break;
                    case 'M':
                        result += 1000;
                        break;
                    default:
                        break;
                }
                S.insert(s[i]);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}