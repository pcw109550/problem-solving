#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Bitset {
    vector<unsigned int> T;
    int _size;
    int cnt;
    bool flipped;
public:
    Bitset(int size): _size(size)  {
        T = vector<unsigned int> (size / 32 + ((size % 32) != 0));     
        cnt = 0;
        flipped = false;
    }
    
    void fix(int idx) {
        bool prev = (T[idx / 32] >> (idx % 32)) & 1;
        if (!prev && !flipped) {
            T[idx / 32] += (1 << (idx % 32));
            cnt++;
        } else if (prev && flipped) {
            T[idx / 32] -= (1 << (idx % 32));
            cnt--;
        }
    }
    
    void unfix(int idx) {
        bool prev = (T[idx / 32] >> (idx % 32)) & 1;
        if (prev && !flipped) {
            T[idx / 32] -= (1 << (idx % 32));
            cnt--;
        } else if (!prev && flipped) {
            T[idx / 32] += (1 << (idx % 32));
            cnt++;
        }
    }
    
    void flip() {
        flipped = !flipped;
    }
    
    bool all() {
        return (flipped ? _size - cnt : cnt) == _size;
    }
    
    bool one() {
        return (flipped ? _size - cnt : cnt) > 0;
    }
    
    int count() {
        return (flipped ? _size - cnt : cnt);
    }
    
    string toString() {
        string result (_size, '0');
        for (int idx = 0; idx < _size; idx++) {
            bool prev = ((T[idx / 32] >> (idx % 32)) & 1);
            result[idx] = (flipped ? 1 - prev : prev) + '0';
        }
        return result;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */