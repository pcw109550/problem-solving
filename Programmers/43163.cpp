#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

inline bool is_close(string s1, string s2) {
    int diff = 0;
    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != s2[i])
            diff++;
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 1 << 30;
    int N = words.size();
    queue<pair<string, int> > Q;
    vector<bool> visited(50, false);
    Q.push({begin, 0});
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        if (current.first == target) {
            answer = std::min(answer, current.second);
            continue;
        }
        for (int i = 0; i < N; i++)
            if (!visited[i] && is_close(current.first, words[i])) {
                visited[i] = true;
                Q.push({words[i], current.second + 1});
            }
    }
    return answer == 1 << 30 ? 0 : answer;
}

int main(void) {
}