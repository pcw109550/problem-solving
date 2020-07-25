#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Game {
    public:
        Game(int n);
        void initMap(void);
        void printMap(void);
        bool updatePos(void);
        int getTime(void);
    private:
        int N;
        int Map[20][20];
        pair<int, int> baby_pos;
        int baby_size;
        int acc, time;
};

int Game::getTime(void) {
    return time;
}

Game::Game(int n) {
    N = n;
    baby_size = 2;
    acc = 0;
    time = 0;
}

bool Game::updatePos(void) {
    bool visited[N][N] = {};
    int distance[N][N] = {};
    queue<pair<int, int> > Q;
    Q.push(baby_pos);
    visited[baby_pos.first][baby_pos.second] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir];
            int Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= N)
                continue;
            if (!visited[X][Y] && baby_size >= Map[X][Y]) {
                visited[X][Y] = true;
                distance[X][Y] = distance[current.first][current.second] + 1;
                Q.push({X, Y});
            }
        }
    }
    vector<pair<int, int> > cands[N * N] = {};
    pair<int, int> next_pos;
    int Min = 1 << 30;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (Map[i][j] != 0 && baby_size > Map[i][j] && visited[i][j]) {
                cands[distance[i][j]].push_back({i, j});
                Min = min(Min, distance[i][j]);
            }
    if (Min == 1 << 30)
        return false;
    time += Min;
    next_pos = cands[Min][0];
    Map[next_pos.first][next_pos.second] = 0;
    baby_pos = next_pos;
    acc++;
    if (acc == baby_size) {
        acc = 0;
        baby_size++;
    }
    return true;
}

void Game::printMap(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << Map[i][j] << ' ';
        cout << '\n';
    }
}

void Game::initMap(void) {
    int temp;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == 9) {
                baby_pos = {i, j};
                Map[i][j] = 0;
            } else {
                Map[i][j] = temp;
            }
        }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    Game game(N);
    game.initMap();
    while (game.updatePos());
    cout << game.getTime();
}