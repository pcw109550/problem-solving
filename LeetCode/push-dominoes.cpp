// 838. Push Dominoes
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        // O(N)
        int N = dominoes.size();
        vector<bool> visited (N, false);
        vector<char> result (N, '.');
        unordered_map<int, int> M;
        for (int i = 0; i < N; i++)
            if (dominoes[i] != '.') {
                result[i] = dominoes[i];
                visited[i] = true;
                M[i] = dominoes[i] == 'L' ? -1 : 1;
            }
        while (!M.empty()) {
            unordered_map<int, int> temp;
            unordered_map<int, int> next;
            for (auto it : M) {
                if (it.second == -1 && it.first - 1 >= 0 && !visited[it.first - 1])
                    temp[it.first - 1] -= 1;
                else if (it.second == 1 && it.first + 1 < N && !visited[it.first + 1])
                    temp[it.first + 1] += 1;
            }
            for (auto it : temp)
                if (it.second != 0) {
                    if (it.second == -1) {
                        result[it.first] = 'L';
                        next[it.first] = -1;
                    } else if (it.second == 1) {
                        result[it.first] = 'R';
                        next[it.first] = 1;
                    }
                    visited[it.first] = true;
                }
            M = next;
        }
        return string(result.begin(), result.end());
    }
};

int main(void) {
    Solution s;
}