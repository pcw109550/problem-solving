#include<bits/stdc++.h>
using namespace std;
#define FILTER -1
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Room {
    public:
        Room(int r, int c);
        void initMap(void);
        void printMap(void);
        void update(void);
        int getSum(void);
    private:
        void updateDust(void);
        void updateFilter(void);
        int cntSpread(pair<int, int> pos);
        int Map[50][50];
        int R, C;
        pair<int, int> filter_pos[2];
};

Room::Room(int r, int c) {
    R = r;
    C = c;
}

int Room::cntSpread(pair<int, int> pos) {
    int spread_cnt = 0;
    for (int dir = 0; dir < 4; dir++) {
        int X = pos.first + dx[dir];
        int Y = pos.second + dy[dir];
        if (X < 0 || Y < 0 || X >= R || Y >= C)
            continue;
        if (Map[X][Y] == FILTER)
            continue;
        spread_cnt++;
    }
    return spread_cnt;
}

void Room::updateDust(void) {
    int updated_Map[R][C] = {};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int spread_cnt = cntSpread({i, j});
            int spread_amount = Map[i][j] / 5;
            int remain = Map[i][j] - spread_amount * spread_cnt;
            for (int dir = 0; dir < 4; dir++) {
                int X = i + dx[dir];
                int Y = j + dy[dir];
                if (X < 0 || Y < 0 || X >= R || Y >= C)
                    continue;
                if (Map[X][Y] == FILTER)
                    continue;
                updated_Map[X][Y] += spread_amount;
            }
            updated_Map[i][j] += remain;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            Map[i][j] = updated_Map[i][j];
        }
    }
}

void Room::updateFilter(void) {
    pair<int, int> pos[2];
    pos[0] = filter_pos[0];
    pos[1] = filter_pos[1];
    int current = 0;    
    for (int j = 0; j < C - 1; j++) {
        pos[0].second++;
        int next = Map[pos[0].first][pos[0].second];
        Map[pos[0].first][pos[0].second] = current;
        current = next;
    }
    for (int i = 0; i < filter_pos[0].first; i++) {
        pos[0].first--;
        int next = Map[pos[0].first][pos[0].second];
        Map[pos[0].first][pos[0].second] = current;
        current = next;
    }
    for (int j = 0; j < C - 1; j++) {
        pos[0].second--;
        int next = Map[pos[0].first][pos[0].second];
        Map[pos[0].first][pos[0].second] = current;
        current = next;
    }
    for (int i = 0; i < filter_pos[0].first - 1; i++) {
        pos[0].first++;
        int next = Map[pos[0].first][pos[0].second];
        Map[pos[0].first][pos[0].second] = current;
        current = next;
    }

    current = 0;
    for (int j = 0; j < C - 1; j++) {
        pos[1].second++;
        int next = Map[pos[1].first][pos[1].second];
        Map[pos[1].first][pos[1].second] = current;
        current = next;
    }
    for (int i = 0; i < R - filter_pos[1].first - 1; i++) {
        pos[1].first++;
        int next = Map[pos[1].first][pos[1].second];
        Map[pos[1].first][pos[1].second] = current;
        current = next;
    }
    for (int j = 0; j < C - 1; j++) {
        pos[1].second--;
        int next = Map[pos[1].first][pos[1].second];
        Map[pos[1].first][pos[1].second] = current;
        current = next;
    }
    for (int i = 0; i < R - filter_pos[1].first - 2; i++) {
        pos[1].first--;
        int next = Map[pos[1].first][pos[1].second];
        Map[pos[1].first][pos[1].second] = current;
        current = next;
    }
}

void Room::update(void) {
    updateDust();
    updateFilter();
}

void Room::printMap(void) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << Map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Room::initMap(void) {
    int filter_cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == FILTER)
                filter_pos[filter_cnt++] = {i, j};
        }
    }
}

int Room::getSum(void) {
    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Map[i][j] != -1)
                sum += Map[i][j];
        }
    }
    return sum;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int R, C, T;
    cin >> R >> C >> T;
    Room room(R, C);
    room.initMap();
    while (T--)
        room.update();
    cout << room.getSum();
}