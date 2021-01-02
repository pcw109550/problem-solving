// 1640. Check Array Formation Through Concatenation
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        bool canFormArray(std::vector<int>& arr, std::vector<std::vector<int> >& pieces) {
            // O(N)
            std::unordered_map<int, int> M;
            for (int i = 0; i < pieces.size(); i++) {
                M[pieces[i][0]] = i;
            }
            int i = 0;
            while (i < arr.size()) {
                if (M.find(arr[i]) == M.end())
                    return false;
                int cand = M[arr[i]];
                for (int j = 0; j < pieces[cand].size(); j++) {
                    if (pieces[cand][j] != arr[i++])
                        return false;
                }
            }
            return true;
        }
};

class Solution2 {
    public:
        bool canFormArray(std::vector<int>& arr, std::vector<std::vector<int> >& pieces) {
            // O(N ** 2)
            int i = 0;
            while (i < arr.size()) {
                int cand = -1;
                for (int j = 0; j < pieces.size(); j++) {
                    if (pieces[j][0] == arr[i]) {
                        cand = j;
                        break;
                    }    
                }
                if (cand == -1)
                    return false;
                for (int j = 0; j < pieces[cand].size(); j++) {
                    if (pieces[cand][j] != arr[i++])
                        return false;
                }
            }
            return true;
        }
};

int main(void) {
    Solution s;
}