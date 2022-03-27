// 402. Remove K Digits
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // O(N)
        string result;
        int N = num.size();
        result.push_back(num[0]);
        int cnt = k;
        for (int i = 1; i < N; i++) {
            char cur = num[i];
            while (!result.empty() && result.back() > cur && cnt > 0) {
                result.pop_back();
                cnt--;
            }
            result.push_back(cur);
        }
        while (cnt > 0) {
            cnt--;
            result.pop_back();
        }
        string temp; bool start = true;
        for (auto it : result) {
            if (start && it == '0')
                continue;
            else {
                start = false;
                temp.push_back(it);
            }
        }
        result = temp;
        if (result.empty())
            result.push_back('0');
        return result;
    }
};

int main(void) {
    Solution s;
}
