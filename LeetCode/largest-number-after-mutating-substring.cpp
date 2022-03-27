// 1946. Largest Number After Mutating Substring
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        // O(N)
        string result;
        int N = num.size();
        bool conv = false, done = false;
        for (int i = 0; i < N; i++) {
            if (done) {
                result.push_back(num[i]);
                continue;
            }
            char cand = change[num[i] - '0'] + '0';
            if (!conv && num[i] < cand) {
                conv = true;
                result.push_back(cand);
            } else if (!conv && num[i] >= cand) {
                result.push_back(num[i]);  
            } else if (conv && num[i] <= cand) {
                result.push_back(cand);
            } else if (conv && num[i] > cand) {
                done = true;
                result.push_back(num[i]);
            }
        }
        return result;
    }
}; 

int main(void) {
    Solution s;
}
