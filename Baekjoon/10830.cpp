#include <bits/stdc++.h>
using namespace std;

int N; long long B;

void printmat(int X[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << X[N * i + j];
            if (j != N - 1) { cout << ' '; }
        }
        cout << '\n';
    }
}

void mulmat(int X[], int Y[], int result[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[N * i + j] += X[N * i + k] * Y[N * k + j];
                result[N * i + j] %= 1000;
            }
        }
    }
}

void copymat(int dest[], int src[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dest[N * i + j] = src[N * i + j];
        }
    }
}

void powmat(int A[], long long B, int result[]) {
    if (B == 1) { copymat(result, A); return; }
    int temp[N][N] = {};
    int resultMat[N][N] = {};
    powmat(A, B / 2, (int *)temp);
    mulmat((int *)temp, (int *)temp, (int *)resultMat);
    if (B % 2 == 1) {
        int resultMat2[N][N] = {};
        mulmat(A, (int *)resultMat, (int *)resultMat2);
        copymat(result, (int *)resultMat2);
    } else {
        copymat(result, (int *)resultMat);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> B; int A[N][N] = {}, result[N][N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j]; A[i][j] %= 1000;
        }
    }
    powmat((int *)A, B, (int *)result);
    printmat((int *)result);
}