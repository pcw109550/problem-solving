#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int Map[1500][1500];
bool visited[1500][1500];
unordered_set<int> border;
int R, C;
vector<pair<int, int> > mySet;
vector<pair<int, int> > pos;

inline int encode(pair<int, int> coord) {
    return coord.first * C + coord.second;
}

inline pair<int, int> decode(int compressed) {
    return {compressed / C, compressed % C};
}

int Find(int x) {
    if (mySet[x].second < 0) { return x; }
    // Path compression
    return mySet[x].second = Find(mySet[x].second);
}

void Union(pair<int, int> x, pair<int, int> y) {
    // O(invack(N))
    int X = Find(encode(x));
    int Y = Find(encode(y));
    if (X == Y) { return; }
    if (mySet[X].first < mySet[Y].first) {
        swap(X, Y);
    }
    mySet[Y].second = X;
    if (mySet[X].first == mySet[Y].first) {
        mySet[X].first++;
    }
}

inline void insert_neighbors(unordered_set<int> &edge, pair<int, int> coord) {
    for (int dir = 0; dir < 4; dir++) {
        int X = coord.first + dx[dir];
        int Y = coord.second + dy[dir];
        if (X < 0 || Y < 0 || X >= R || Y >= C)
            continue;
        if (!visited[X][Y] && Map[X][Y]) {
            visited[X][Y] = true;
            edge.insert(encode({X, Y}));
        }
    }
}

void print_map(void) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << (Map[i][j] ? 'X' : '.');
        cout << endl;
    }
}

void print_set(void) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << setw(3) << Find(encode({i, j})) << ' ';
        cout << endl;
    }   
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    // O(R * C)
    cin >> R >> C;
    mySet = vector<pair<int, int> >(R * C, {0, -1});
    char temp;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> temp;
            Map[i][j] = temp == 'X';
            if (temp == 'L')
                pos.push_back({i, j});
        }
    queue<pair<int, int> > Q;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (visited[i][j] || Map[i][j])
                continue;
            pair<int, int> start = {i, j};
            visited[i][j] = true;
            Q.push({i, j});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                insert_neighbors(border, current);
                for (int dir = 0; dir < 4; dir++) {
                    int X = current.first + dx[dir];
                    int Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= R || Y >= C)
                        continue;
                    if (!visited[X][Y] && !Map[X][Y]) {
                        visited[X][Y] = true;
                        Union(start, {X, Y});
                        Q.push({X, Y});
                    }
                }
            }
        }
    int result = 0;
    while (Find(encode(pos[0])) != Find(encode(pos[1]))) {
        result++;
        // melt
        unordered_set<int> next_border;
        for (auto coord_encoded : border) {
            auto coord = decode(coord_encoded);
            Map[coord.first][coord.second] = 0;
            for (int dir = 0; dir < 4; dir++) {
                int X = coord.first + dx[dir];
                int Y = coord.second + dy[dir];
                if (X < 0 || Y < 0 || X >= R || Y >= C)
                    continue;
                if (!Map[X][Y]) {
                    Union(coord, {X, Y});
                } else if (Map[X][Y] && !visited[X][Y]) {
                    visited[X][Y] = true;
                    next_border.insert(encode({X, Y}));
                }
            }
        }
        border = next_border;
    }
    cout << result;
}