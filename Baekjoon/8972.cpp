#include<bits/stdc++.h>
using namespace std;
enum State { Empty, Robot, I };

class Game {
    public:
        Game(int r, int c);
        void initMap(void);
        void printMap(void);
        bool update(int input);
    private:
        bool updateMyPos(int input);
        bool updateCrazyRobots(void);
        pair<int, int> nextPos(pair<int, int> robot_pos);
        int Map[100][100];
        int R, C;
        pair<int, int> my_pos;
};

Game::Game(int r, int c) {
    R = r;
    C = c;
}

bool Game::updateMyPos(int input) {
    if (input == 5)
        return true;
    pair<int, int> next_pos = my_pos;
    if (input == 1 || input == 2 || input == 3)
        next_pos.first++;
    if (input == 7 || input == 8 || input == 9) 
        next_pos.first--;
    if (input == 1 || input == 4 || input == 7)
        next_pos.second--;
    if (input == 3 || input == 6 || input == 9)
        next_pos.second++;
    int X = next_pos.first;
    int Y = next_pos.second;
    if (X < 0 || Y < 0 || X >= R || Y >= C)
        return true;
    if (Map[X][Y] == Robot)
        return false;
    Map[my_pos.first][my_pos.second] = Empty;
    Map[X][Y] = I;
    my_pos.first = X;
    my_pos.second = Y;
    return true;
}

pair<int, int> Game::nextPos(pair<int, int> robot_pos) {
    pair<int, int> next_pos = robot_pos;
    if (robot_pos.first > my_pos.first)
        next_pos.first--;
    if (robot_pos.first < my_pos.first)
        next_pos.first++;
    if (robot_pos.second > my_pos.second)
        next_pos.second--;
    if (robot_pos.second < my_pos.second)
        next_pos.second++;
    return next_pos;
}

bool Game::updateCrazyRobots(void) {
    int update_cnt[R][C] = {};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Map[i][j] == Robot) {
                pair<int, int> next_pos = nextPos({i, j});
                if (Map[next_pos.first][next_pos.second] == I)
                    return false;
                update_cnt[next_pos.first][next_pos.second]++;
                Map[i][j] = Empty;
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (update_cnt[i][j] == 1)
                Map[i][j] = Robot;
        }
    }
    return true;
}

bool Game::update(int input) {
    if (!updateMyPos(input))
        return false;
    if (!updateCrazyRobots())
        return false;
    return true;
}

void Game::printMap(void) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Map[i][j] == Empty) {
                cout << '.';
            } else if (Map[i][j] == Robot) {
                cout << 'R';
            } else if (Map[i][j] == I) {
                cout << 'I';
            } else {
                assert(false);
            }
        }
        cout << '\n';
    }
}

void Game::initMap(void) {
    char temp;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> temp;
            if (temp == '.') {
                Map[i][j] = Empty;
            } else if (temp == 'R') {
                Map[i][j] = Robot;
            } else if (temp == 'I') {
                Map[i][j] = I;
                my_pos.first = i;
                my_pos.second = j;
            } else {
                assert(false);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int R, C;
    string tape;
    cin >> R >> C;
    Game game(R, C);
    game.initMap();
    cin >> tape;
    for (int i = 0; i < tape.length(); i++) {
        int input = static_cast<int>(tape[i] - '0');
        if (!game.update(input)) {
            cout << "kraj " << i + 1 << '\n';
            return 0;
        }
    }
    game.printMap();
}