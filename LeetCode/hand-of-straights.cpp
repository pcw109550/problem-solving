#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // O(N * log(N))
        int N = hand.size();
        if (N % groupSize)
            return false;
        map<int, int> M;
        for (auto c : hand)
            M[c]++;
        while (!M.empty()) {
            auto it = M.begin();
            int val = it->first, cnt = it->second;
            M[val]--;
            if (M[val] == 0)
                M.erase(val);
            for (int i = val + 1; i < val + groupSize; i++) {
                if (!M.count(i))
                    return false;
                M[i]--;
                if (M[i] == 0)
                    M.erase(i);
            }   
        }
        return true;
    }
};