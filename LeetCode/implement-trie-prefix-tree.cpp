// 208. Implement Trie (Prefix Tree)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode *> M;
    bool end;
    TrieNode() { end = false; }
    bool contains_key(char c) { return M.count(c); }
    TrieNode* get(char c) {
        return M[c];
    }
    void put(char c, TrieNode *node) {
        M[c] = node;
    }
    void set_end() {
        end = true;
    }
    bool is_end() {
        return end;
    }
};

class Trie {
    TrieNode *root;
    public:
        /** Initialize your data structure here. */
        Trie() {
            root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        void insert(std::string word) {
            // O(N)
            auto node = root;
            for (auto c : word) {
                if (!node->contains_key(c))
                    node->put(c, new TrieNode());
                node = node->get(c);
            }
            node->set_end();
        }

        /** Returns if the word is in the trie. */
        bool search(std::string word) {
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
        bool startsWith(std::string word) {
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

int main(void) {
    Trie *obj = new Trie();
}