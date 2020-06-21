#include <bits/stdc++.h>
using namespace std;
#define NUMMOVE 10
enum Dir { Up, Dn, Lt, Rt };
int N, M, result;
int Map[10][10];
pair<int, int> B, R, O;

void printMap(pair<int, int> b, pair<int, int> r) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (make_pair(i, j) == b)      { cout << 'B'; }
            else if (make_pair(i, j) == r) { cout << 'R'; }
            else if (Map[i][j] == 0)       { cout << '.'; }
            else                           { cout << '#'; }
        } cout << '\n';
    }
}

int cnt;

inline tuple<pair<int, int>, pair<int, int>, bool> update(pair<int, int> b, pair<int, int> r, Dir dir, int trial) {
    pair<int, int> prevb = b, prevr = r; bool state = true;
    switch (dir) {
        case Up:
            if (b.first < r.first) {
                while (state && !Map[b.first - 1][b.second]) {
                    b.first--;
                    if (b == O) { state = false; }
                }
                while (state && !Map[r.first - 1][r.second]) {
                    r.first--;
                    if (b == r) { r.first++; break; }
                    if (r == O) { state = false; result = trial + 1; }
                }
            } else {
                while (state && !Map[r.first - 1][r.second]) {
                    r.first--;
                    if (r == O) { state = false; result = trial + 1; }
                }
                while (!Map[b.first - 1][b.second]) {
                    b.first--;
                    if (b == r) {
                        if (b == O) { result = 0; }
                        b.first++;
                        break;
                    }
                    if (b == O) { state = false; } 
                }
            }
            break;
        case Dn:
            if (b.first < r.first) {
                while (state && !Map[r.first + 1][r.second]) {
                    r.first++;
                    if (r == O) { state = false; result = trial + 1; }
                }
                while (!Map[b.first + 1][b.second]) {
                    b.first++;
                    if (b == r) {
                        if (b == O) { result = 0; }
                        b.first--;
                        break;
                    }
                    if (b == O) { state = false; }
                }
            } else {
                while (state && !Map[b.first + 1][b.second]) {
                    b.first++;
                    if (b == O) { state = false; }
                }
                while (state && !Map[r.first + 1][r.second]) {
                    r.first++;
                    if (b == r) { r.first--; break; }
                    if (r == O) { state = false; result = trial + 1; }
                }
            }
            break;
        case Lt:
            if (b.second < r.second) {
                while (state && !Map[b.first][b.second - 1]) {
                    b.second--;
                    if (b == O) { state = false; }
                }
                while (state && !Map[r.first][r.second - 1]) {
                    r.second--;
                    if (b == r) { r.second++; break; }
                    if (r == O) { state = false; result = trial + 1; }
                }
            } else {
                while (state && !Map[r.first][r.second - 1]) {
                    r.second--;
                    if (r == O) { state = false; result = trial + 1; }
                }
                while (!Map[b.first][b.second - 1]) {
                    b.second--;
                    if (b == r) {
                        if (b == O) { result = 0; }
                        b.second++;
                        break;
                    }   
                    if (b == O) { state = false; } 
                }
            }
            break;
        case Rt:
            if (b.second < r.second) {
                while (state && !Map[r.first][r.second + 1]) {
                    r.second++;
                    if (r == O) { state = false; result = trial + 1;}
                }
                while (!Map[b.first][b.second + 1]) {
                    b.second++;
                    if (b == r) {
                        if (b == O) { result = 0; }
                        b.second--;
                        break;
                    }
                    if (b == O) { state = false;  }
                }
            } else {
                while (state && !Map[b.first][b.second + 1]) {
                    b.second++;
                    if (b == O) { state = false; }
                }
                while (state && !Map[r.first][r.second + 1]) {
                    r.second++;
                    if (b == r) { r.second--; break; }
                    if (r == O) { state = false; result = trial + 1; }
                }
            }
            break;
        default:
            assert (false);
            break;
    }
    //cout << dir << '\n';
    //printMap(b, r);
    /*if (result) {
        cout << state << '\n';
        printMap(b, r);
        cout << result << '\n';
        exit(0);
    }*/
    return make_tuple(b, r, state);
}

inline void task() {
    queue<tuple<pair<int, int>, pair<int, int>, int, int> > Q;
    tuple<pair<int, int>, pair<int, int>, bool> it;
    Q.push(make_tuple(B, R, 0, -1));
    while (!Q.empty() && !result) {
        pair<int, int> b, r; int trial, prev;
        tie(b, r, trial, prev) = Q.front(); Q.pop();
        if (trial >= NUMMOVE) { continue; }
        if (prev == -1 || prev == 1) { // prev movement Lt or Rt or None
            it = update(b, r, Up, trial);
            if (get<2>(it)) { Q.push(make_tuple(get<0>(it), get<1>(it), trial + 1, 0)); }
            it = update(b, r, Dn, trial);
            if (get<2>(it)) { Q.push(make_tuple(get<0>(it), get<1>(it), trial + 1, 0)); }
        }
        if (prev == -1 || prev == 0) { // prev movement Up or Dn or None
            it = update(b, r, Lt, trial);
            if (get<2>(it)) { Q.push(make_tuple(get<0>(it), get<1>(it), trial + 1, 1)); }
            it = update(b, r, Rt, trial);
            if (get<2>(it)) { Q.push(make_tuple(get<0>(it), get<1>(it), trial + 1, 1)); }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    char temp; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            switch (temp) {
                case '#':
                    Map[i][j] = 1;
                    break;
                case '.':
                    break;
                case 'R':
                    R = make_pair(i, j);
                    break;
                case 'B':
                    B = make_pair(i, j);
                    break;
                case 'O':
                    O = make_pair(i, j);
                    break;
                default:
                    assert(false);
                    break;
            }
        }
    }
    task();
    cout << (!result ? -1 : result);
}