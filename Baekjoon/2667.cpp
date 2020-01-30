#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void debug(int *input, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
           printf("%d ", *(input + i * N + j));
        }
        printf("\n");
    }
}

int main(void) {
    int N; scanf("%d", &N); char temp[N + 1];
    int input[N][N] = {}; int prim = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s", &temp);
        for (int j = 0; j < N; j++) {
            input[i][j] = temp[j] == '1';
            prim |= input[i][j];
        }
    }
    if (!prim) { cout << 0; return 0; }
    int count = 1; list<int> result; int size = 1;
    queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (input[i][j] == 1) {
                Q.push({i, j}); input[i][j] = count + 1;
                while (!Q.empty()) {
                    pair<int, int> current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir]; int Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
                        if (input[X][Y] == 1) {
                            input[X][Y] = count + 1; Q.push({X, Y}); size++;
                        }
                    }
                }
                //debug((int *)&input, N); cout << "\n";
                count++; result.push_back(size);
                size = 1;
            }
        }
    }
    cout << count - 1 << "\n";
    result.sort();
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << "\n";
    }
}