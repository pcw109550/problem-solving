// 705. Design HashSet
#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
    vector<bool> S;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        S = vector<bool> (1000001, false);
    }
    
    void add(int key) {
        S[key] = true;
    }
    
    void remove(int key) {
        S[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return S[key];
    }
};

int main(void) {
    MyHashSet* obj = new MyHashSet();
}
