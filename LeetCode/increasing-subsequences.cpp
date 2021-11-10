// 491. Increasing Subsequences
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

struct TrieNode {
    std::unordered_map<int, TrieNode *> M;
    bool end;
    TrieNode() { end = false; }
    bool contains_key(int c) { return M.count(c); }
    TrieNode* get(int c) {
        return M[c];
    }
    void put(int c, TrieNode *node) {
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
        void insert(vector<int> &word) {
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
        bool search(vector<int> &word) {
            // O(N)
            auto node = root;
            for (auto c : word) {
                if (!node->contains_key(c))
                    return false;
                node = node->get(c);
            }
            return node->is_end();
        }
};

class Solution {
    Trie *trie;
    vector<vector<int> > result;
    int N;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // O(N * 2 ** N)
        trie = new Trie();
        N = nums.size();
        backtrack(nums, 0, vector<int>{});
        return result;   
    }
    
    void backtrack(vector<int>& nums, int idx, vector<int> prev) {
        if (prev.size() >= 2) {
            if (!trie->search(prev)) {
                trie->insert(prev);
                result.push_back(prev);
            }
        }   
        if (idx == N)
            return;
        backtrack(nums, idx + 1, prev);
        int pb = prev.empty() ? INT_MIN : prev.back();
        if (pb <= nums[idx]) {
            prev.push_back(nums[idx]);
            backtrack(nums, idx + 1, prev);
        }
    }
};

int main(void) {
    Solution s;
}