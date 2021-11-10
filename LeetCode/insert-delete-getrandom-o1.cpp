// 380. Insert Delete GetRandom O(1)
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
using namespace std;

class RandomizedSet {
    random_device rd;
    mt19937 gen;
    unordered_map<int, int> M;
    uniform_real_distribution<double> dist;
    vector<int> input;
public:
    RandomizedSet() {
        gen = mt19937(rd());
        dist = uniform_real_distribution<double>(0, 1);
    }
    
    int genRand(int N) {
        // O(1)
        return static_cast<int>(dist(gen) * N);
    }
    
    bool insert(int val) {
        // O(1)
        if (M.count(val))
            return false;
        input.push_back(val);
        M[val] = input.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        // O(1)
        if (!M.count(val))
            return false;
        int idx = M[val];
        int back = input.back();
        swap(input[idx], input[input.size() - 1]);
        input.pop_back();
        M[back] = idx;
        M.erase(val);
        return true;
    }
    
    int getRandom() {
        // O(1)
        int idx = genRand(input.size());
        return input[idx];
    }
};

int main(void) {
    RandomizedSet* obj = new RandomizedSet();
}
