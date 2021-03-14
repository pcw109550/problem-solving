#include <bits/stdc++.h>
using namespace std;

int sum(string a) {
    int result = 0;
    for (auto it : a)
        if (isdigit(it))
            result += it - '0';
    return result;
}

bool compare(string a, string b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    int sum_a = sum(a);
    int sum_b = sum(b);
    if (sum_a != sum_b)
        return sum_a < sum_b;
    return a < b;    
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    int N; cin >> N;
    string temp;
    vector<string> input;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        input.push_back(temp);
    }
    sort(input.begin(), input.end(), compare);
    for (auto it : input)
        cout << it << '\n';
}