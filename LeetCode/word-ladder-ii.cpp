// 126. Word Ladder II
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <climits>
#include <queue>
using namespace std;

class Solution {
    vector<vector<string> > result;
    unordered_map<string, unordered_set<int> > M;
    vector<unordered_set<int> > parent;
    int N;
    int L;
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // O(N * K ** 2)
        N = wordList.size();
        parent = vector<unordered_set<int> > (N, unordered_set<int>());
        // O(N * K)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < wordList[i].size(); j++) {
                char temp = wordList[i][j];
                wordList[i][j] = '*';
                M[wordList[i]].insert(i);
                wordList[i][j] = temp;
            }
        }
        L = INT_MAX;
        
        queue<pair<int, int> > Q;
        Q.push({-1, 0}); // beginWord
        int last_idx = -1;
        unordered_map<int, int> last_seen;
        
        // BFS with efficient branch cutting
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int idx = cur.first;
            int len = cur.second;
            if (len > L)
                continue;
            auto curWord = idx == -1 ? beginWord : wordList[idx];
            if (curWord == endWord) {
                L = len;
                last_idx = idx;
                continue;
            }
            for (int i = 0; i < curWord.size(); i++) {
                char temp = curWord[i];
                curWord[i] = '*';
                for (auto it : M[curWord])
                    if (!last_seen.count(it) || last_seen[it] == len) {
                        last_seen[it] = len;
                        parent[it].insert(idx);
                        Q.push({it, len + 1});
                    }
                curWord[i] = temp; 
            }
        }
        
        // DFS
        if (last_idx != -1) 
            backtrack(last_idx, vector<int>(), wordList, beginWord);
        
        return result;
    }
    
    void backtrack(int idx, vector<int> trace, vector<string>& wordList, string& beginWord) {
        trace.push_back(idx);
        if (idx == -1) {
            vector<string> path;
            for (int i = trace.size() - 1; i >= 0; i--)
                path.push_back(trace[i] == -1 ? beginWord : wordList[trace[i]]);
            result.push_back(path);
            return;
        }
        for (auto par_idx : parent[idx]) 
            backtrack(par_idx, trace, wordList, beginWord);
        trace.pop_back();
    }
};

class Solution2 {
    vector<vector<string> > result;
    unordered_map<string, unordered_set<int> > M;
    vector<bool> visited;
    string b, e;
    int N;
    int L;
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // O(N * K ** 2) but TLE, no efficient branch cutting
        N = wordList.size();
        b = beginWord;
        e = endWord;
        visited = vector<bool> (N, false);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < wordList[i].size(); j++) {
                char temp = wordList[i][j];
                wordList[i][j] = '*';
                M[wordList[i]].insert(i);
                wordList[i][j] = temp;
            }
        }
        L = INT_MAX;
        vector<int> trace;
        traversal(b, trace, wordList);
        return result;
    }
    
    void traversal(string curWord, vector<int>& trace, vector<string>& wordList) {
        if (trace.size() > L)
            return;
        if (curWord == e) { 
            if (L < trace.size())
                return;
            if (L > trace.size()) {
                result.clear();
                L = trace.size();
            }
            vector<string> path;
            path.push_back(b);
            for (int i = 0; i < trace.size(); i++)
                path.push_back(wordList[trace[i]]);
            result.push_back(path);
            return;
        }
        for (int i = 0; i < curWord.size(); i++) {
            char temp = curWord[i];
            curWord[i] = '*';
            for (auto it : M[curWord]) 
                if (!visited[it]) {
                    visited[it] = true;
                    trace.push_back(it);
                    traversal(wordList[it], trace, wordList); 
                    trace.pop_back();
                    visited[it] = false;
                }
            curWord[i] = temp;
        }
    }
};

int main(void) {
    Solution s;
}