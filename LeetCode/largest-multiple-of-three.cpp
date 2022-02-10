// 1363. Largest Multiple of Three
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        // O(N * log(N))
        string result;
        int N = digits.size();
        unordered_map<char, int> M;
        for (int i = 0; i < N; i++) {
            if (digits[i] % 3 == 0)
                result.push_back(digits[i] + '0');
            else
                M[digits[i] + '0']++;
        }
        
        string s1;
        s1 += string(M['8'], '8');
        s1 += string(M['5'], '5');
        s1 += string(M['2'], '2');

        string s2;
        s2 += string(M['7'], '7');
        s2 += string(M['4'], '4');
        s2 += string(M['1'], '1');
        
        int q1 = s1.size() / 3, r1 = s1.size() % 3;
        int q2 = s2.size() / 3, r2 = s2.size() % 3;

        bool flag = (r1 == 0 && r2 == 2) || (r1 == 2 && r2 == 0);
        
        if (flag) {
            if ((q1 - (r1 == 0)) >= 0) {
                result += s1.substr(0, (q1 - (r1 == 0)) * 3);
                s1 = s1.substr((q1 - (r1 == 0)) * 3);
            }
            if ((q2 - (r2 == 0)) >= 0) {
                result += s2.substr(0, (q2 - (r2 == 0)) * 3);
                s2 = s2.substr((q2 - (r2 == 0)) * 3);
            }
        } else {
            result += s1.substr(0, q1 * 3);
            s1 = s1.substr(q1 * 3);

            result += s2.substr(0, q2 * 3);
            s2 = s2.substr(q2 * 3);
        }
        
        int p1 = 0, p2 = 0;
        while (p1 < s1.size() && p2 < s2.size()) {
            result.push_back(s1[p1]); p1++;
            result.push_back(s2[p2]); p2++;
        }
        
        sort(result.begin(), result.end(), greater<>());
        if (result[0] == '0')
            return string(1, '0');
        return result;
    }
};

int main(void) {
    Solution s;
}
