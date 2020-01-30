#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    
    list<int> temp;
    for (int i = 1; i <= N; i++) {
        temp.push_back(i);
    }
    
    int store;
    list<int>::iterator idx = temp.begin();
    advance(idx, K - 1);
    cout << "<";
    int cnt = 0;
    while (temp.size() != 1) {
        cout << *idx << ", ";
        idx = temp.erase(idx);
        store = (distance(temp.begin(), idx) + K - 1) % temp.size();
        idx = temp.begin();
        advance(idx, store);
    }
    cout << *temp.begin() << ">";
}