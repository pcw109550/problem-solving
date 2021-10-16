// 212. Word Search II
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct TrieNode {
    std::unordered_map<char, TrieNode *> M;
    bool end;
    int end_idx;
    TrieNode() { end = false; }
    bool contains_key(char c) { return M.count(c); }
    TrieNode* get(char c) {
        return M[c];
    }
    void put(char c, TrieNode *node) {
        M[c] = node;
    }
    void set_end(int idx) {
        end = true;
        end_idx = idx;
    }
    void unset_end() {
        end = false;
        end_idx = 0;
    }
    bool is_end() {
        return end;
    }
    int get_end_idx() {
        return end_idx;
    }
};

struct Trie {
        TrieNode *root;
        /** Initialize your data structure here. */
        Trie() {
            root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        void insert(string word, int idx) {
            // O(N)
            auto node = root;
            for (auto c : word) {
                if (!node->contains_key(c))
                    node->put(c, new TrieNode());
                node = node->get(c);
            }
            node->set_end(idx);
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            // O(N)
            auto node = root;
            for (auto c : word) {
                if (!node->contains_key(c))
                    return false;
                node = node->get(c);
            }
            return node->is_end();
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string word) {
            // O(N)
            auto node = root;
            for (auto c : word) {
                if (!node->contains_key(c))
                    return false;
                node = node->get(c);
            }
            return true;
        }
};


class Solution {
    int M, N, k;
    Trie *trie;
    vector<vector<bool> > visited;
    vector<string> result;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // O(k * L + M * N * 3 ** L)  
        M = board.size(), N = board[0].size(), k = words.size();
        trie = new Trie();
        visited = vector<vector<bool> >(M, vector<bool>(N, false));
        // O(k * L)
        for (int i = 0; i < k; i++)
            trie->insert(words[i], i);
        // O(M * N * 3 ** L)
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                backtrack(board, words, trie->root, i, j);
        return result;
    }
    
    void backtrack(vector<vector<char> > &board, vector<string>& words, TrieNode *node, int i, int j) {
        if (!node->contains_key(board[i][j]))
            return;
        if (visited[i][j])
            return;
        visited[i][j] = true;
        auto next_node = node->get(board[i][j]);
        if (next_node->is_end()) {
            result.push_back(words[next_node->get_end_idx()]);
            next_node->unset_end();
        }
        for (int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];
            if (x < 0 || y < 0 || x >= M || y >= N)
                continue;
            backtrack(board, words, next_node, x, y);
        }
        visited[i][j] = false;
    
    }
};

int main(void) {
    Solution s;
}