// 443. String Compression
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int probe;
public:
    int compress(vector<char>& chars) {
        // O(N)
        probe = 0;
        int result = 0;
        char cur = '\0';
        int num = 0;
        int N = chars.size();
        for (int i = 0; i < N; i++) {
            char c = chars[i];
            if (c == cur)
                num++;
            else {
                result += eval(chars, cur, num);
                cur = c;
                num = 1;
            }
        }
        if (num > 0)
            result += eval(chars, cur, num);
        return result;
    }
    
    inline int eval(vector<char>& chars, char c, int num) {
        if (num == 0)
            return num;
        if (num == 1) {
            chars[probe++] = c;
            return num;
        }
        auto exp_res = expand(num);
        chars[probe++] = c;
        for (auto it = exp_res.rbegin(); it != exp_res.rend(); it++)
            chars[probe++] = *it + '0';
        return 1 + exp_res.size();
    }
    
    inline vector<int> expand(int num) {
        vector<int> res;
        while (num > 0) {
            res.push_back(num % 10);
            num /= 10;
        }
        return res;
    }
};

int main(void) {
    Solution s;
}