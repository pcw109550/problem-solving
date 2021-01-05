#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    unordered_set<int> S, S2;
    for (auto it : reserve)
        S.insert(it);
    sort(lost.begin(), lost.end());
    for (auto it : lost) {
        if (S.find(it) != S.end()) {
            S.erase(it);
            continue;
        }
        S2.insert(it);
    }
    for (auto it : lost) {
        if (S2.find(it) == S2.end())
            continue;
        if (S.find(it - 1) != S.end()) {
            S.erase(it - 1);
            continue;
        }
        if (S.find(it + 1) != S.end()) {
            S.erase(it + 1);
            continue;
        }
        answer--;
    }
    return answer;
}

int main(void) {
}