#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        // O(N * log(N))
        int N = s.size();
        sort(s.begin(), s.end());
        int result = 0;
        vector<int> D(N + 1);
        for (int i = 0; i < N; i++)
            D[i + 1] = D[i] + s[i];
        int state = 0;
        for (int i = N - 1; i >= 0; i--) {
            state += D[N] - D[i];
            result = max(result, state);
        } 
        return result;
    }
};

class Solution2 {
public:
    int maxSatisfaction(vector<int>& s) {
        // O(N ** 3)
        int N = s.size();
        sort(s.begin(), s.end());
        int result = 0;
        for (int l = 1; l <= N; l++) {
            for (int i = N - l; i >= 0; i--) {
                int temp = 0;
                for (int j = i + 1 ; j < i + 1 + l; j++) 
                    temp += (j - i) * s[j - 1];
                if (result > temp)
                    break;
                result = max(result, temp);
            }
        }
        return result;
    }
};