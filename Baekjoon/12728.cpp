#include <bits/stdc++.h>
using namespace std;

template <class T>
void mulmat(T X[], T Y[], T result[], T ring) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[2 * i + j] += X[2 * i + k] * Y[2 * k + j];
                result[2 * i + j] %= ring;
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
void powmat(T A[], T B, T result[], T ring) {
    if (B == 0) { return; }
    if (B == 1) { copymat<T>(result, A); return; }
    T temp[2][2] = {};
    T resultMat[2][2] = {};
    powmat<T>(A, B / 2, (T *)temp, ring);
    mulmat<T>((T *)temp, (T *)temp, (T *)resultMat, ring);
    if (B % 2 == 1) {
        T resultMat2[2][2] = {};
        mulmat<T>(A, (T *)resultMat, (T *)resultMat2, ring);
        copymat<T>(result, (T *)resultMat2);
    } else {
        copymat<T>(result, (T *)resultMat);
    }
}

inline void format(int t, int result) {
    if (result < 0)
        result += 1000;
    string s = to_string(result);
    if (s.size() < 3)
        s.insert(s.begin(), 3 - s.size(), '0');
    cout << "Case #" << t << ": " << s << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, T;
    int c1 = 6, c2 = 28;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        if (n == 1) {
            format(t, c1 - 1);
            continue;
        }
        if (n == 2) {
            format(t, c2 - 1);
            continue;
        }
        int A[2][2] = {{6, -4}, {1, 0}}, result[2][2] = {{0, 0}, {0, 0}};
        powmat<int>((int *)A, n - 2, (int *)result, 1000);
        format(t, (result[0][0] * c2 + result[0][1] * c1 - 1) % 1000);
    }
}    