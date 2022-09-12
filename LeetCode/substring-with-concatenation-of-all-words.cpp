#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // O(N * K ** 2)
        vector<int> result;
        int N = s.size();
        int L = words.size();
        int K = words[0].size();
        multiset<string> S_orig;
        for (int i = 0; i < words.size(); i++)
            S_orig.insert(words[i]);
        multiset<string> S;
        for (int i = 0; i < K; i++) {
            S.clear();
            for (int j = 0; j < N / K; j++) {
                if (L * K <= i + j * K) {
                    string word_deleted = s.substr(i + j * K - L * K, K);
                    if (word_deleted.size() < K)
                        continue;
                    auto it = S.find(word_deleted);
                    if (it != S.end())
                        S.erase(it);
                }
                string word = s.substr(i + j * K, K);
                if (word.size() < K)
                    break;
                S.insert(word);           
                if (S.size() == L && S == S_orig)
                    result.push_back(i + j * K + K - L * K);
            }
        }
        return result;
    }
};