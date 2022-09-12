#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        // O(N * log(N))
        int N = tiles.size();
        int result = 0;
        sort(tiles.begin(), tiles.end());
        vector<int> starts(N);
        vector<int> prefix_sum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            starts[i] = tiles[i][0];
            prefix_sum[i + 1] = prefix_sum[i] + tiles[i][1] - tiles[i][0] + 1;
        }
        for (int i = 0; i < N; i++) {
            int temp_result = 0;
            int start_pos = tiles[i][0];
            int end_pos = start_pos + carpetLen - 1;
            auto it = upper_bound(starts.begin() + i, starts.end(), end_pos);
            int delta_len = it - starts.begin() - i;
            temp_result += prefix_sum[i + delta_len - 1] - prefix_sum[i];
            temp_result += min(end_pos, tiles[i + delta_len - 1][1]) - tiles[i + delta_len - 1][0] + 1;
            result = max(result, temp_result);
        }
        return result;
    }
};