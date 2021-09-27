// 1239. Maximum Length of a Concatenated String with Unique Characters
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
    int result = 0;
    int N;
public:
    int maxLength(vector<string>& arr) {
        // O(2 ** N)
        N = arr.size();
        vector<int> input;
        for (auto word : arr)
            input.push_back(translate(word));
        traversal(arr, input, 0, 0, 0);
        return result;
    }
    
    void traversal(vector<string> &arr, vector<int> &input, int idx, int cur, int len) {
        if (idx == N) {
            result = max(result, len);
            return;
        }
        traversal(arr, input, idx + 1, cur, len);
        if (!(cur & input[idx]) && input[idx] != INT_MAX)
            traversal(arr, input, idx + 1, cur | input[idx], len + arr[idx].size());        
    }
    
    inline int translate(string &word) {
        int result = 0;
        for (auto c : word) {
            if (result & (1 << (c - 'a')))
                return INT_MAX;
            result |= (1 << (c - 'a'));
        }
        return result;
    }
};

int main(void) {
    Solution s;
}