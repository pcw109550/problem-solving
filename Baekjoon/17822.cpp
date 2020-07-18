#include<bits/stdc++.h>
using namespace std;
#define EMPTY -1
enum Rotate { CW, CCW };

class Disc {
    public:
        Disc(int n, int m);
        void initDisc(void);
        void printDisc(void);
        void update(int x, int d, int k);
        int getSum(void);
    private:
        void rotateDiscs(int x, int d, int k);
        void rotateDisc(int disc_num, int d, int k);
        bool updateAdjacent(void);
        void updateByAvg(void);
        int Map[50][50];
        int N, M, num_empty;
};

Disc::Disc(int n, int m) {
    N = n; // number of discs
    M = m;
    num_empty = 0;
}

void Disc::updateByAvg(void) {
    int sum = getSum();
    int not_empty = N * M - num_empty;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Map[i][j] == EMPTY)
                continue;
            if (sum > not_empty * Map[i][j])
                Map[i][j]++;
            else if (sum < not_empty * Map[i][j])
                Map[i][j]--;
        }
    }
}

bool Disc::updateAdjacent(void) {
    bool updated = false;
    bool update_map[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Map[i][j] == EMPTY)
                continue;
            int current = Map[i][j];
            bool adjacent = false;
            if (Map[i][(j + 1) % M] == current) {
                update_map[i][(j + 1) % M] = true;
                adjacent = true;
            }
            if (Map[i][(j + M - 1) % M] == current) {
                update_map[i][(j + M - 1) % M] = true;
                adjacent = true;
            }
            if (i > 0 && Map[i - 1][j] == current) {
                update_map[i - 1][j] = true;
                adjacent = true;
            }
            if (i < N - 1 && Map[i + 1][j] == current) {
                update_map[i + 1][j] = true;
                adjacent = true;
            }
            if (adjacent) {
                update_map[i][j] = true;
                updated = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (update_map[i][j]) {
                Map[i][j] = EMPTY;
                num_empty++;
            }
        }
    }
    return updated;
}

void Disc::update(int x, int d, int k) {
    rotateDiscs(x, d, k);
    if (!updateAdjacent()) {
        updateByAvg();
    }
}

void Disc::rotateDisc(int disc_num, int d, int k) {
    int delta = d == CW ? M - k : k;
    int updated_disc[M] = {};
    for (int j = 0; j < M; j++)
        updated_disc[j] = Map[disc_num][(j + delta) % M];
    for (int j = 0; j < M; j++)
        Map[disc_num][j] = updated_disc[j];
}

void Disc::rotateDiscs(int x, int d, int k) {
    for (int disc_num = x - 1; disc_num < N; disc_num += x)
        rotateDisc(disc_num, d, k);
}

int Disc::getSum(void) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Map[i][j] != EMPTY)
                sum += Map[i][j];
        }
    }
    return sum;
}

void Disc::printDisc(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << Map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Disc::initDisc(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, T, x, d, k;
    cin >> N >> M >> T;
    Disc disc(N, M);
    disc.initDisc();
    while (T--) {
        cin >> x >> d >> k;
        disc.update(x, d, k);
    }
    cout << disc.getSum();
}