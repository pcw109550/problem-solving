#include <bits/stdc++.h>
using namespace std;

void debug(int *input, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", *(input + j + i * M));
        }
        printf("\n");
    }
}

int main(void) {
    //ios::sync_with_stdio(0); ci   n.tie(0);
    int N, M; scanf("%d %d\n", &N, &M); int input[N][M]; int fast = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &input[i][j]);
            fast |= input[i][j];
        }
    }
    if (fast == 0) {printf("%d\n%d", 0, 0); return 0; }
    int cnt = 0, size = 0, maxsize = 0;
    // debug((int *)&input, N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (input[i][j] == 1) {
                q.push(make_pair(i, j)); input[i][j] += 1;
                do {
                    pair<int, int> current = q.front(); q.pop();
                    int x = current.first; int y = current.second;
                    if (y - 1 >= 0     && input[x][y - 1] == 1) { q.push(make_pair(x, y - 1)); input[x][y - 1] += 1; }
                    if (y + 1 <= M - 1 && input[x][y + 1] == 1) { q.push(make_pair(x, y + 1)); input[x][y + 1] += 1; }    
                    if (x - 1 >= 0     && input[x - 1][y] == 1) { q.push(make_pair(x - 1, y)); input[x - 1][y] += 1; }
                    if (x + 1 <= N - 1 && input[x + 1][y] == 1) { q.push(make_pair(x + 1, y)); input[x + 1][y] += 1; }
                    size++;
                } while (!q.empty());
                cnt++;
                if (maxsize < size) { maxsize = size; }
                size = 0;
            }
        }
    }
    printf("%d\n%d", cnt, maxsize);
}