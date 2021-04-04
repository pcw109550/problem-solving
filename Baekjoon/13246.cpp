#include <bits/stdc++.h>
using namespace std;
#define RING 1000

template <class T, class Q>
struct Mat {
    T N;
    vector<vector<T> > M;
    Mat(T n, T t = 0): N(n) {
        M = vector<vector<T> > (N, vector<T> (N));
        for (T i = 0; i < N; i++)
            for (T j = 0; j < N; j++)
                M[i][j] = i == j ? t : 0;
    }
    
    Mat(vector<vector<T> >&m) {
        N = m.size();
        M = m;
    }

    void operator= (const Mat &r) {
        M = r.M;
    }

    inline T& operator () (T x, T y) {
        return M[x][y];
    }

    Mat operator* (Mat &r) {
        Mat result(N);
        for (T i = 0; i < N; i++)
            for (T j = 0; j < N; j++)
                for (T k = 0; k < N; k++)
                    result(i, j) = (result(i, j) + M[i][k] * r(k, j)) % RING;
        return result;
    }

    Mat operator+ (Mat &r) {
        Mat result(N);
        for (T i = 0; i < N; i++)
            for (T j = 0; j < N; j++)
                result(i, j) = (M[i][j] + r(i, j)) % RING;
        return result;
    }

    Mat operator- (Mat &r) {
        Mat result(N);
        for (T i = 0; i < N; i++)
            for (T j = 0; j < N; j++)
                result(i, j) = (M[i][j] - r(i, j) + RING) % RING;
        return result;
    }

    Mat operator^ (Q r) {
        Mat result(N, 1);
        Mat t = M;
        while (r) {
            if (r & 1)
                result = result * t;
            t = t * t;
            r >>= 1;
        }
        return result;
    }

    friend ostream& operator<< (ostream& os, const Mat<T, Q>& M) {
        for (T i = 0; i < M.N; i++) {
            for (T j = 0; j < M.N; j++) {
                os << M.M[i][j] << ' ';
            }
            os << '\n';
        }
        return os;
    }
};

template <class T, class Q>
Mat<T, Q> sum(Mat<T, Q> &A, Q B) {
    Q N = A.N;
    Mat<T, Q> I (N, 1);
    if (!B)
        return I;
    if (B == 1)
        return A + I;
    if (B % 2) {
        auto t1 = I;
        auto t2 = A ^ (B / 2 + 1);
        auto t3 = sum(A, B / 2);
        t1 = t1 + t2;
        t1 = t1 * t3;
        return t1;
    }
    auto t1 = I;
    auto t2 = sum(A, B / 2 - 1);
    auto t3 = A ^ (B / 2);
    auto t4 = A ^ B;
    t1 = t1 + t3;
    t1 = t1 * t2;
    t1 = t1 + t4;
    return t1;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N, B, temp; cin >> N >> B;
    vector<vector<long long> > base (N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> temp;
            base[i][j] = temp % RING;
        }
    Mat<long long, long long> M(base);
    Mat<long long, long long> I(N, 1);
    auto result = sum<long long, long long>(M, B) - I;
    cout << result;
}