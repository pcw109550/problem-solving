// 648. Replace Words
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
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
            for (auto c : s) {
                if (!probe->contains(c))
                    probe->insert(c);
                probe = probe->next(c);
            }
            probe->set_end();
        }
    
        string process(string &s) {
            TrieNode *probe = root;
            string result;
            for (auto c : s) {
                if (probe->is_end())
                    return result;
                if (probe->contains(c)) {
                    result.push_back(c);
                    probe = probe->next(c);
                } else
                    return s;
            }
            return s;
        }
};


class Solution {
    Trie *T;
    public:
        string replaceWords(vector<string>& dictionary, string sentence) {
            // O(M * N)
            T = new Trie();
            for (auto root : dictionary)
                T->insert(root);
            string result;
            istringstream f(sentence);
            string token;
            while (getline(f, token, ' ')) {
                auto res = T->process(token);
                result += res;
                result.push_back(' ');
            }
            if (result.back() == ' ')
                result.pop_back();
            return result;
        }
};

int main(void) {
    Solution s;
}