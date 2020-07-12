#include<bits/stdc++.h>
using namespace std;
enum State { Empty, Snake, Apple };
enum Dir   { W, A, S, D };
enum Rot   { Fw, Lt, Rt };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

class Game {
    public:
        Game(int n);
        void addApple(pair<int, int> &pos);
        bool update(Rot rot);
        void printMap(void);
        int getResult(void);
    private:
        int map[100][100];
        int N;
        int result;
        Dir nextDir(Rot rot);
        pair<int, int> nextPos(Dir dir);
        Dir head_dir;
        pair<int, int> head_pos;
        vector<pair<pair<int, int>, Dir> > snake;
};

Game::Game(int n) {
    fill(*map, *map + 10000, Empty);
    result = 0;
    N = n;
    head_dir = D;
    snake.push_back({{0, 0}, D});
    map[0][0] = Snake;
}

void Game::printMap(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int Game::getResult(void) {
    return result;
}

void Game::addApple(pair<int, int> &pos) {
    map[pos.first][pos.second] = Apple;
}

bool Game::update(Rot rot) {
    result++;
    Dir dir = nextDir(rot);
    pair<int, int> pos = nextPos(dir);
    int X = pos.first, Y = pos.second;
    if (X < 0 || Y < 0 || X >= N || Y >= N || map[X][Y] == Snake) {
        return false;
    }
    if (map[X][Y] != Apple) {
        auto tail = snake.back().first;
        map[tail.first][tail.second] = Empty;
        snake.pop_back();
    }
    map[X][Y] = Snake;
    snake.insert(snake.begin(), {pos, dir});
    head_dir = dir;
    head_pos = pos;
    return true;
}

pair<int, int> Game::nextPos(Dir dir) {
    return make_pair(head_pos.first + dx[dir], head_pos.second + dy[dir]);
}

Dir Game::nextDir(Rot rot) {
    switch (rot) {
        case Fw:
            return head_dir;
        case Lt:
            return static_cast<Dir>((head_dir + 1) % 4);
        case Rt:
            return static_cast<Dir>((head_dir + 3) % 4);
        default:
            assert(false);
            break;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K, L, x, y, t; char rot;
    cin >> N;
    Game game(N);
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        pair<int, int> pos = make_pair(x - 1, y - 1);
        game.addApple(pos);
    }
    cin >> L;
    Rot plan[10000];
    fill(plan, plan + 10000, Fw);
    for (int i = 0; i < L; i++) {
        cin >> t >> rot;
        plan[t] = rot == 'L' ? Lt : Rt;
    }
    for (int i = 0; i < 10000; i++) {
        // game.printMap();
        if (!game.update(plan[i])) {
            break;
        }
    }
    cout << game.getResult();
}