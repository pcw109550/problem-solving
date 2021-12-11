// 519. Random Flip Matrix
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
using namespace std;

class Solution {
    random_device rd;
    mt19937 gen;
    int M, N;
    uniform_int_distribution<> X, Y;
    unordered_set<int> S;
    bool is_min;
    vector<vector<int> > temp;
    int idx;
public:
    Solution(int m, int n) : M(m), N(n) {
        // O(1)
        gen = mt19937(rd());
        is_min = M * N <= 1000;
        if (is_min) {
            // O(M * N)
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    temp.push_back(vector<int> {i, j});
            shuffle(temp.begin(), temp.end(), rd);
        } else {
            // O(1)
            X = uniform_int_distribution<>(0, M - 1);
            Y = uniform_int_distribution<>(0, N - 1);
        }
    }
    
    vector<int> flip() {
        vector<int> result;
        if (is_min) {
            // O(1)
            result = temp[idx++];
        } else {
            // Rejection sampling
            // P = (M * N - 1) / (M * N)
            // E = 1 * P + 2 * P ** 2 + ... 
            // O(E)
            int x, y, k;
            while (true) {
                x = X(gen);
                y = Y(gen);
                k = M * x + y;
                if (!S.count(k))
                    break;
            } 
            S.insert(k);
            result = vector<int> {x, y};
        }
        return result;
    }
    
    void reset() {
        if (is_min) {
            // O(M * N)
            shuffle(temp.begin(), temp.end(), rd);
            idx = 0;
        } else {
            // O(M * N)
            S.clear();   
        }
    }
};

int main(void) {
    Solution* obj;
}