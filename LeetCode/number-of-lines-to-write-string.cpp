#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        // O(N)
        vector<int> result;
        int cur_length = 0, num_row = 1;
        for (auto c : s) {
            int width = widths[c - 'a'];
            if (cur_length + width > 100) {
                cur_length = width;
                num_row++;
            } else 
                cur_length += width;
        }
        result = vector<int> {num_row, cur_length};
        return result;
    }
};