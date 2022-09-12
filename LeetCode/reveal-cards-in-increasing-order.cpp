#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // O(N * log(N))
        int N = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> Q;
        for (int i = 0; i < N; i++)
            Q.push(i);
        vector<int> idxs;
        int i = 0;
        while (!Q.empty()) {
            int top = Q.front();
            Q.pop();
            if (i % 2 == 0)
                idxs.push_back(top);
            else
                Q.push(top);
            i++;
        }
        vector<int> result(N);
        for (int i = 0; i < N; i++)
            result[idxs[i]] = deck[i];
        return result;
    }
};