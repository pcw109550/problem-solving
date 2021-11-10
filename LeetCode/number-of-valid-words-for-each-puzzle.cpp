// 1178. Number of Valid Words for Each Puzzle
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // O(N * M)
        vector<int> result;
        vector<int> words_enc, puzzles_enc;
        int M = words.size();
        int N = puzzles.size();
        for (auto word : words)
            words_enc.push_back(encode(word));
        for (auto puzzle : puzzles)
            puzzles_enc.push_back(encode(puzzle));
        for (int i = 0; i < N; i++) {
            int puzzle_enc = puzzles_enc[i];
            int cnt = 0;
            for (auto word_enc : words_enc) {
                if (((word_enc | puzzle_enc) == puzzle_enc) && (1 << (puzzles[i][0] - 'a')) & word_enc)
                    cnt++;
            }
            result.push_back(cnt);
        }
        return result;
    }
    
    inline int encode(string &word) {
        int result = 0;
        for (auto c : word)
            result |= (1 << (c - 'a'));
        return result;
    }
};

int main(void) {
    Solution s;
}