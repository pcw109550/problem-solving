#include<bits/stdc++.h>
using namespace std;
#define FIELD 1000000007

template <class T>
void mulmat(T X[], T Y[], T result[]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[2 * i + j] += X[2 * i + k] * Y[2 * k + j];
                result[2 * i + j] %= FIELD;
            }
        }
    }
}

template <class T>
void copymat(T dest[], T src[]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            dest[2 * i + j] = src[2 * i + j];
        }
    }
}

template <class T>
void powmat(T A[], T B, T result[]) {
    if (B == 1) { copymat<T>(result, A); return; }
    T temp[2][2] = {};
    T resultMat[2][2] = {};
    powmat<T>(A, B / 2, (T *)temp);
    mulmat<T>((T *)temp, (T *)temp, (T *)resultMat);
    if (B % 2 == 1) {
        T resultMat2[2][2] = {};
        mulmat<T>(A, (T *)resultMat, (T *)resultMat2);
        copymat<T>(result, (T *)resultMat2);
    } else {
        copymat<T>(result, (T *)resultMat);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N, M;
    cin >> N >> M;
    long long gcd = __gcd(N, M);
    if (gcd == 1) {
        cout << gcd;
        return 0;
    }
    gcd--;
    long long A[2][2] = {{1, 1}, {1, 0}}, result[2][2] = {};
    powmat<long long>((long long *)A, gcd, (long long *)result);
    cout << result[0][0];    
}   