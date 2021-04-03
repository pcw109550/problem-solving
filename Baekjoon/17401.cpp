#include <bits/stdc++.h>
using namespace std;
#define FIELD 1000000007

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
                    result(i, j) = (result(i, j) + M[i][k] * r(k, j)) % FIELD;
        return result;
    }

    Mat operator^ (Q &r) {
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

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long t, n, d; cin >> t >> n >> d;
    vector<Mat<long long, int> > ms;
    for (long long i = 0; i < t; i++) {
        int cnt, a, b, c; cin >> cnt;
        Mat<long long, int> m(n);
        while (cnt--) {
            cin >> a >> b >> c;
            a--; b--;
            m(a, b) = c;
        }
        ms.push_back(m);
    }
    Mat<long long, int> period(n, 1);
    for (auto mat : ms)
        period = period * mat;
    Mat<long long, int> result(n);
    int k = d / t;
    result = period ^ k;
    for (int i = 0; i < d % t; i++)
        result = result * ms[i];
    cout << result;
}