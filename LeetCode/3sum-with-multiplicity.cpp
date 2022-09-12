 #include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#define FIELD 1000000007

class Solution {
    public:
        int threeSumMulti(std::vector<int>& arr, int target) {
            // O(N ** 2)
            int result = 0;
            int N = arr.size();
            std::unordered_map<int, int> M;
            for (int i = 0; i < N; i++) {
                result = (result + M[target - arr[i]]) % FIELD;
                for (int j = 0; j < i; j++)
                    M[arr[i] + arr[j]]++;
            }
            return result;
        }
};

class Solution2 {
    public:
        int threeSumMulti(std::vector<int>& arr, int target) {
            // O(N ** 2 * log(N))
            int result = 0;
            int N = arr.size();
            for (int i = 0; i < N; i++) {
                std::unordered_map<int, std::vector<int> > M;
                for (int j = i + 1; j < N; j++)
                    M[arr[j]].push_back(j);
                for (int j = i + 1; j < N; j++) {
                    int temp = target - arr[i] - arr[j];
                    if (M.count(temp)) {
                        int acc = M[temp].end() - std::upper_bound(M[temp].begin(), M[temp].end(), j);
                        result = (result + acc) % FIELD;
                    }
                }
            }
            return result;
        }
};