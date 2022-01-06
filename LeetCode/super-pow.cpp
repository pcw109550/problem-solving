// 372. Super Pow
#include <iostream>
#include <vector>
using namespace std;
#define RING 1337 

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        // O(N)
        long long result = 1;
        int N = b.size();
        long long t = a % RING;
        for (int i = N - 1; i >= 0; i--) {
            result = (result * pow(t, b[i])) % RING;
            t = pow(t, 10);
        }
        return result;
    }
    
    inline int pow(int a, int k) {
        long long result = 1;
        for (int i = 0; i < k; i++)
            result = (result * a) % RING;
        return result;
    }
};

int main(void) {
    Solution s;
}