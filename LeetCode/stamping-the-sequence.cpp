// 936. Stamping The Sequence
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        std::vector<int> movesToStamp(std::string stamp, std::string target) {
            // O(N ** 2 * M)
            std::vector<int> result;
            std::unordered_set<int> idxs;
            int N = target.size(), M = stamp.size();
            int cnt = 0;
            int trial = 0;
            for (int i = 0; i <= N - M; i++)
                idxs.insert(i);
            
            while (trial < 10 * N && cnt < N) {
                int max_idx = -1;
                int cur_cnt = 0;
                int temp_cnt;
                for (auto i : idxs) {
                    temp_cnt = compare(stamp, target, i);
                    if (temp_cnt > 0) {
                        if (cur_cnt < temp_cnt) {
                            cur_cnt = temp_cnt;
                            max_idx = i;
                        }   
                    }
                }
                if (max_idx == -1)
                    break;
                for (int i = max_idx; i < max_idx + M; i++)
                    target[i] = '?';
                idxs.erase(max_idx);
                cnt += cur_cnt;
                result.push_back(max_idx);
                trial++;
            }
            if (cnt != N)
                return std::vector<int> ();
            std::reverse(result.begin(), result.end());
            return result;
        }
    
        inline int compare(std::string &stamp, std::string &target, int start) {
            int cnt = 0;
            for (int i = 0; i < stamp.size(); i++) {
                if (target[start + i] == '?' || target[start + i] == stamp[i]) {
                    if (target[start + i] == stamp[i])
                        cnt++;
                } else
                    return 0;
            }
            return cnt;
        }
};

int main(void) {
    Solution s;
}