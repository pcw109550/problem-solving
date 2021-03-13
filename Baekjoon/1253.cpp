#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N ** 2)
    int N, temp, result = 0; cin >> N;
    vector<int> input;
    unordered_map<int, int> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        input.emplace_back(temp);
        M[temp]++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (input[j] == 0) {
                if (input[i] != 0 && M[input[i]] >= 2) {
                    result++;
                    break;
                }
                if (input[i] == 0 && M[input[i]] >= 3) {
                    result++;
                    break;
                }
                continue;
            }
            int target = input[i] - input[j];
            if (!M.count(target))
                continue;
            if (target == input[j] && M[input[j]] >= 2) {
                result++;
                break;
            }
            if (target != input[j]) {
                result++;
                break;
            }
        }
    }
    cout << result;
}
