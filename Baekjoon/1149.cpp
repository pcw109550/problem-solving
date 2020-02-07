#include <bits/stdc++.h>
using namespace std;
enum color {RED, GREEN, BLUE};
int R[1001], G[1001], B[1001];
int D[1001][3];

int main(void) {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> R[i] >> G[i] >> B[i];
    }
    D[1][RED] = R[1]; D[1][GREEN] = G[1]; D[1][BLUE] = B[1];
    for (int i = 2; i <= N; i++) {
        D[i][RED] = min(D[i - 1][GREEN], D[i - 1][BLUE]) + R[i];
        D[i][GREEN] = min(D[i - 1][RED], D[i - 1][BLUE]) + G[i];
        D[i][BLUE] = min(D[i - 1][RED], D[i - 1][GREEN]) + B[i];    
    }
    cout << min(D[N][RED], min(D[N][GREEN], D[N][BLUE]));
}