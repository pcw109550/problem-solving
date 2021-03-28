#include <bits/stdc++.h>
using namespace std;
#define FIELD 1000000007

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int D; cin >> D;
    vector<vector<int> > path;
    path.push_back({1, 3});
    path.push_back({0, 2, 3});
    path.push_back({1, 3, 4, 5});
    path.push_back({0, 1, 2, 5});
    path.push_back({2, 5, 6});
    path.push_back({2, 3, 4, 7});
    path.push_back({4, 7});
    path.push_back({5, 6});
    vector<int> A(8, 0); A[0] = 1;
    for (int i = 0; i < D; i++) {
        vector<int> B(8, 0);
        for (int n = 0; n < 8; n++)
            for (auto adj : path[n])
                B[adj] = (B[adj] + A[n]) % FIELD;
        A = B;
    }
    cout << A[0];
}