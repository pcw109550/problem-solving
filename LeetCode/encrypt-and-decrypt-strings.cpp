#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Encrypter {
    unordered_map<char, string> Map;
    unordered_map<string, unordered_set<char> > C;
    vector<string> P;
    int N, M;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        // O(N + M)
        N = keys.size(), M = dictionary.size();
        for (int i = 0; i < N; i++)
            Map[keys[i]] = values[i];
        for (int i = 0; i < N; i++)
            C[values[i]].insert(keys[i]);
        P = dictionary;
    }
    
    string encrypt(string word1) {
        // O(M)
        string result;
        for (auto c : word1) {
            if (!Map.count(c))
                return string();
            result += Map[c];
        }
        return result;
    }
    
    int decrypt(string word2) {
        // O(M * N)
        int result;
        unordered_set<int> cands;
        for (int i = 0; i < M; i++)
            if (P[i].size() * 2 == word2.size())
                cands.insert(i);
        traversal(word2, 0, cands);
        result = cands.size();
        return result;
    }
    
    void traversal(string &target, int idx, unordered_set<int>& cands) {
        if (idx * 2 == target.size() || cands.size() == 0)
            return;
        string token = target.substr(2 * idx, 2);
        unordered_set<char> cand_char = C[token];
        unordered_set<int> erased;
        for (int pos : cands)
            if (!cand_char.count(P[pos][idx]))
                erased.insert(pos);        
        for (auto pos : erased)
            cands.erase(pos);
        traversal(target, idx + 1, cands);
    }
    
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */