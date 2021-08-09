// 677. Map Sum Pairs
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class MapSum {
    unordered_map<string, int> M;
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        // O(1)
        M[key] = val;
    }
    
    int sum(string prefix) {
        // O(N)
        int result = 0;
        for (auto it : M)
            if (it.first.substr(0, prefix.size()) == prefix)
                result += it.second;
        return result;
    }
};

int main(void) {
    MapSum* obj = new MapSum();
}
