#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // O(N)
        vector<string> result;
        int cur = 1, probe = 0;
        while (cur <= n && probe < target.size()) {
            while (cur < target[probe]) {
                result.push_back("Push");
                result.push_back("Pop");
                cur++;
            }
            probe++;
            cur++;
            result.push_back("Push");
        }
        return result;
    }
};