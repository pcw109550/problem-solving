// 1286. Iterator for Combination
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

class CombinationIterator {
    string chars;
    int L, C;
    vector<int> state;
    bool next_s;
public:
    CombinationIterator(string characters, int combinationLength) {
        chars = characters;
        L = combinationLength;
        C = characters.size() - 1;
        state = vector<int> (L);
        iota(state.begin(), state.end(), 0);
        next_s = true;
    }
    
    inline void print_state() {
        for (auto it : state)
            cout << it << ' ';
        cout << endl;
    }
    
    inline void update_state() {
        // O(L)
        int probe = L - 1;
        bool updated = false;
        for (int idx = L - 1; idx >= 0; idx--) {
            if (state[idx] != C - (L - 1 - idx)) {
                probe = idx;
                updated = true;
                break;
            }
        }
        int start = state[probe];
        for (int idx = probe; idx < L; idx++) 
            state[idx] = start + (idx - probe) + 1;
        if (!updated)
            next_s = false;
    }
    
    string next() {
        // O(L)
        string result;
        for (auto idx : state)
            result.push_back(chars[idx]);
        update_state();
        return result;
    }
    
    bool hasNext() {
        // O(1)
        return next_s;
    }
};

int main(void) {
    CombinationIterator* obj;
}
