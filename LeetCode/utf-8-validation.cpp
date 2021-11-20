// 393. UTF-8 Validation
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // O(N)
        int N = data.size();
        vector<vector<bool> > _data;
        for (int i = 0; i < N; i++)
            _data.push_back(spread(data[i]));
        bool cur = false;
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (!cur) {
                if (!_data[i][0])
                    continue;
                if (_data[i][0] && !_data[i][1])
                    return false;
                count = 0;
                for (int j = 0; j < 4; j++)
                    if (_data[i][j])
                        count++;
                    else
                        break;
                if (_data[i][count])
                    return false;
                cur = true;
                count--;
                continue;
            }
            if (count >= 1) {
                count--;
                if (!(_data[i][0] && !_data[i][1]))
                    return false;
            }
            if (count == 0)
                cur = false;
        }
        return !cur;
    }
    
    inline vector<bool> spread(int i) {
        // O(1)
        vector<bool> result(8, false);
        for (int j = 7; j >= 0; j--) {
            result[j] = i & 1;
            i >>= 1;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
