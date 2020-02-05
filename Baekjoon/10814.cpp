#include <bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
    int age1 = a.first.first, idx1 = a.first.second; string name1 = a.second;
    int age2 = b.first.first, idx2 = b.first.second; string name2 = b.second;
    if (age1 < age2) { return true; }
    else if (age1 > age2) { return false; }
    if (idx1 < idx2) { return true; }
    else { return false; }
}

int main(void) {
    int N, age; string name; cin >> N; pair<pair<int, int>, string> input[N];
    for (int i = 0; i < N; i++) {
        cin >> age >> name; input[i] = {{age, i}, name};
    }
    sort(input, input + N, comp);
    for (int i = 0; i < N; i++) {
        age = input[i].first.first; name = input[i].second;
        cout << age << " " << name << "\n";
    }
}