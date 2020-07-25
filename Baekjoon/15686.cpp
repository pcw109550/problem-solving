#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, temp;
    vector<pair<int, int> > chicken, house;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == 1)
                house.push_back({i, j});
            else if (temp == 2)
                chicken.push_back({i, j});
        }
    }
    bool ind[chicken.size()] = {};
    int Min = 1 << 30;
    for (int i = 0; i < M; i++)
        ind[i] = true;
    do {
        int sum = 0;
        vector<pair<int, int> > cur_chicken;
        for (int i = 0; i < chicken.size(); i++)
            if (ind[i])
                cur_chicken.push_back(chicken[i]);
        for (auto h : house) {
            int local_min = 1 << 30;
            for (auto c : cur_chicken) {
                int dist = abs(h.first - c.first) + abs(h.second - c.second);
                local_min = min(local_min, dist);
            }
            sum += local_min;
        }
        Min = min(Min, sum);
    } while (prev_permutation(ind, ind + chicken.size()));
    cout << Min;
}