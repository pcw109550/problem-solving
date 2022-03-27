// 957. Prison Cells After N Days
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        // O(2 ** 8)
        vector<int> result;
        unordered_map<int, int> M;
        vector<int> states;
        int L = 0;
        while (true) {
            int enc = encode(cells);
            if (M.count(enc))
                break;
            M[enc] = L++;
            states.push_back(enc);
            next(cells);
        }
        int enc = encode(cells);
        int B = M[enc];
        int P = L - B;
        int N = (n <= B ? n : B + (n - B) % P);
        int res_enc = states[N];
        result = decode(res_enc);
        return result;
    }
    
    inline int encode(vector<int> &cells) {
        int result = 0;
        for (int i = 0; i < 8; i++) {
            result <<= 1;
            result |= cells[i];
        }
        return result;
    }
    
    inline void next(vector<int> &cells) {
        vector<int> result (8, 0);
        for (int i = 1; i < 7; i++)
            result[i] = !(cells[i - 1] ^ cells[i + 1]);
        for (int i = 0; i < 8; i++)
            cells[i] = result[i];
    }
    
    inline vector<int> decode(int s) {
        vector<int> result(8, 0);
        for (int i = 7; i >= 0; i--) {
            result[i] = s & 1;
            s >>= 1;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}