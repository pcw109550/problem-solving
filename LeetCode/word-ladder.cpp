// 127. Word Ladder
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

class Solution {
    public:
        int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
            // O(N ** 2)
            int N = wordList.size();
            std::queue<std::pair<std::string, int> > Q;
            std::vector<bool> visited(N, false);
            Q.push({beginWord, 1});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                auto word = current.first;
                auto len = current.second;
                if (word == endWord)
                    return len;
                for (int i = 0; i < N; i++) {
                    if (!visited[i] && is_close(word, wordList[i])) {
                        visited[i] = true;
                        Q.push({wordList[i], len + 1});
                    }
                }
            }
            return 0;
        }
    
        bool is_close(std::string &a, std::string &b) {
            int num_diff = 0;
            for (int i = 0; i < a.size(); i++)
                if (a[i] != b[i])
                    num_diff++;
            return num_diff == 1;
        }
};

int main(void) {
    Solution s;
}