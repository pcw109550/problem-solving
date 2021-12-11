// 1032. Stream of Characters
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


struct TrieNode {
    unordered_map<char, TrieNode *> M;
    bool end;
    TrieNode () {
        end = false;
    }
    bool is_end() {
        return end;
    }
    void set_end() {
        end = true;
    }
    bool contains(char c) {
        return M.count(c);
    }
    TrieNode *next(char c) {
        return contains(c) ? M[c] : NULL;
    }
    void insert(char c) {
        M[c] = new TrieNode();
    }
};

class Trie {
    public:
        TrieNode *root;
        Trie () {
            root = new TrieNode();
        }

        void insert(string s) {
            TrieNode *probe = root;
            int s_len = s.size();
            for (int i = s_len - 1; i >= 0; i--) {
                char c = s[i];
                if (!probe->contains(c))
                    probe->insert(c);
                probe = probe->next(c);
            }
            probe->set_end();
        }
    
        bool find(vector<char> &query_chars, int max_len) {
            TrieNode *probe = root;
            for (int i = 0; i < max_len && i < query_chars.size(); i++) {
                char c = query_chars[query_chars.size() - 1 - i];
                if (probe->contains(c)) {
                    probe = probe->next(c);
                    if (probe->is_end())
                        return true;
                } else
                    break;
            }
            return false;
        }
};

class StreamChecker {
public:
    vector<char> query_chars;
    Trie *T;
    int max_len;
    // O(M * L + N * L)
    StreamChecker(vector<string>& words) {
        // O(M * L)
        T = new Trie();
        for (auto word: words) {
            T->insert(word);
            max_len = max(max_len, static_cast<int>(word.size()));
        }
    }
    
    bool query(char letter) {
        // O(L)
        query_chars.push_back(letter);
        return T->find(query_chars, max_len);
    }
};

int main() {
    StreamChecker* obj;
}
