#include <bits/stdc++.h>
using namespace std;

long long translate(long long a) {
    long long result = 0;
    while (a) {
        result *= 10;
        result += a % 10;
        a /= 10;
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    int N; cin >> N;
    long long temp;
    vector<long long> input;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        input.push_back(translate(temp));
    }
    sort(input.begin(), input.end());
    for (auto it : input)
        cout << it << '\n';
}