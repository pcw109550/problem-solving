// 658. Find K Closest Elements
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <deque>
using namespace std;

class Solution {
    public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            // O(N)
            auto it = upper_bound(arr.begin(), arr.end(), x);
            vector<int> result;
            int N = arr.size();
            if (it == arr.end()) {
                for (int i = N - k; i < N; i++)
                    result.push_back(arr[i]);
                return result;
            }
            if (it == arr.begin()) {
                for (int i = 0; i < k; i++)
                    result.push_back(arr[i]);
                return result;
            }
            int b = *it; it--;
            int a = *it;
            if (abs(a - x) > abs(b - x))
                it++;
            int start = it - arr.begin();
            deque<int> Q;
            Q.push_back(arr[start]);
            a = start - 1, b = start + 1;
            while (Q.size() < k) {
                if (b >= N)
                    Q.push_front(arr[a--]);
                else if (a < 0)
                    Q.push_back(arr[b++]);
                else {
                    if (abs(arr[a] - x) <= abs(arr[b] - x))
                        Q.push_front(arr[a--]);
                    else
                        Q.push_back(arr[b++]);
                }
            }
            while (!Q.empty()) {
                result.push_back(Q.front());
                Q.pop_front();
            }
            return result;
        }
};


class Solution2 {
    public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            // O(N * log(N))
            vector<int> result;
            vector<pair<int, int> > S;
            int N = arr.size();
            for (int i = 0; i < N; i++)
                S.push_back({abs(arr[i] - x), i});
            sort(S.begin(), S.end());
            for (int i = 0; i < k; i++)
                result.push_back(arr[S[i].second]);
            sort(result.begin(), result.end());
            return result;
        }
};

int main(void) {
    Solution s;
}