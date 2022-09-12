#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // O(N)
        string result;
        vector<pair<int, char> > temp;
        vector<int> left {a, b, c};
        int idx = max_element(left.begin(), left.end()) - left.begin();
        int timer = 0;
        while (result.size() < a + b + c) {
            int appendlen = min(1, left[idx]);
            timer = appendlen == 0 ? timer + 1 : 0;
            if (appendlen > 0) {
                temp.push_back({appendlen, 'a' + idx});
                timer = 0;
                left[idx] -= appendlen;
            } else if (timer == 1)
                break;
            idx = left[(idx + 1) % 3] > left[(idx + 2) % 3] ? (idx + 1) % 3 : (idx + 2) % 3;
        }
        for (auto it : temp) {
            int num = it.first;
            char c = it.second;
            if (left[c - 'a'] > 0) {
                left[c - 'a']--;
                result.append(string (2, c));
            } else
                result.push_back(c);    
        }        
        return result;
    }
};