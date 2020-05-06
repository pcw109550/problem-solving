#include <bits/stdc++.h>
using namespace std;

// Disjoint set without balancing: {parent}
// Needs fundamental understanding of disjoint set
// Review: https://mygumi.tistory.com/245 although #node wrong

int mySet[100001];

int Find(int x) {
    if (mySet[x] == x) { return x; }
    return mySet[x] = Find(mySet[x]);
}

inline void Union(int x, int y) {
    mySet[x] = y;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int G, P, gi, result = 0; cin >> G >> P;
    for (int i = 1; i <= G; i++) {
        mySet[i] = i;
    }
    bool found = false;
    for (int i = 1; i <= P; i++) {
        cin >> gi;
        int parent = Find(gi);
        if (parent) {
            Union(parent, parent - 1);
            result++;
        } else {
            break;
        }
    }
    cout << result;
}