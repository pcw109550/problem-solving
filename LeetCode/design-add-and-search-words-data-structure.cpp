// 211. Design Add and Search Words Data Structure
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode *> M;
    bool end;
    char c;
    TrieNode (char _c): c(_c), end(false) {
    }
    bool has_next(char k) {
        return M.count(k);
    }
    TrieNode *next(char k) {
        return M[k];
    }
    void insert(char k) {
        auto node = new TrieNode(k);
        M[k] = node;
    }
    void set_end() {
        end = true;
    }
    bool is_end() {
        return end;
    }
};

struct Trie {
    TrieNode *dummy;
    Trie () {
        dummy = new TrieNode('0');
    }
    
    void insert(string &word) {
        // O(L)
        auto cur = dummy;
        for (auto c : word) {
            if (!cur->has_next(c))
                cur->insert(c);
            cur = cur->next(c);
        }
        cur->set_end();
    }
    
    bool search(string &word) {
        // O(N * L)
        vector<TrieNode *> curs, nexts;
        curs.push_back(dummy);
        for (auto c : word) {
            nexts.clear();
            for (auto cur : curs) {
                if (c == '.') {
                    for (auto it : cur->M)
                        nexts.push_back(it.second);
                } else if (cur->has_next(c))
                    nexts.push_back(cur->next(c));
            }
            curs = nexts;
        }
        for (auto next : nexts)
            if (next->is_end())
                return true;
        return false;
    }
};

class WordDictionary {
    Trie *trie;
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        // O(L)
        trie->insert(word);
    }
    
    bool search(string word) {
        // O(N * L)
        return trie->search(word);
    }
};

int main(void) {
    WordDictionary* obj = new WordDictionary();
}
