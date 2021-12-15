// 898. Bitwise ORs of Subarrays
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // O(N * K * log(K))
        int N = arr.size();
        int result = 0;
        vector<int> T(N);
        T[N - 1] = arr[N - 1];
        // O(N)
        for (int i = N - 2; i >= 0; i--)
            T[i] = T[i + 1] | arr[i];
        int Max = 0, Min = INT_MAX;
        for (int i = 0; i < N; i++) {
            Max = max(Max, arr[i]);
            Min = min(Min, arr[i]);
        }
        if (Min == 0)
            result++;
        int K = 1;
        for (int i = 30; i >= 0; i--)
            if ((1 << i) & Max) {
                K += i;
                break;
            }
        // O(N * K)
        vector<vector<int> > A(N, vector<int>(K, -1));
        vector<vector<int> > B(K, vector<int>(N, -1));
        for (int k = 0; k < K; k++) {
            for (int i = N - 1; i >= 0; i--) {
                if ((1 << k) & arr[i])
                    A[i][k] = i;
                else if (A[i][k] == -1)
                    A[i][k] = (i < N - 1 ? A[i + 1][k] : -1);
                B[k][i] = A[i][k];
            }
        }
        unordered_set<int> S;
        set<int> store;
        // O(N * K * log(K))
        for (int i = 0; i < N; i++) {
            int cur = T[i];
            for (int k = 0; k < K; k++) {
                if ((1 << k) & cur) {
                    int t = B[k][i]; //[i][k];
                    store.insert(t);
                }                
            }
            int target = 0;
            for (auto it : store) {
                target |= arr[it];
                S.insert(target);
            }
            store.clear();
        }
        result += S.size();
        return result;
    }
};

class Solution2 {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // O(N * K * log(K) * log(N)) TLE
        int N = arr.size();
        int result = 0;
        vector<int> T(N);
        T[N - 1] = arr[N - 1];
        // O(N)
        for (int i = N - 2; i >= 0; i--)
            T[i] = T[i + 1] | arr[i];
        vector<vector<int> > D(30, vector<int>());
        // O(N * K)
        for (int i = 0; i < N; i++)
            for (int k = 0; k < 30; k++) {
                if ((1 << k) & arr[i])
                    D[k].push_back(i);
            }
        // O(N * K * log(K) * log(N))
        unordered_set<int> S;
        for (int i = 0; i < N; i++) {
            int cur = T[i];
            set<int> store;
            for (int k = 0; k < 30; k++) {
                if ((1 << k) & cur) {
                    int t = *lower_bound(D[k].begin(), D[k].end(), i);
                    store.insert(t);
                }                
            }
            int target = 0;
            for (auto it : store) {
                target |= arr[it];
                S.insert(target);
            }
        }
        result = S.size();
        for (int i = 0; i < N; i++)
            if (arr[i] == 0) {
                result++;
                break;
            }
        return result;
    }
};

int main(void) {
    Solution s;
}