#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long> > PQ;
    for (auto val : scoville)
        PQ.push(val);
    while (PQ.size() > 1) {
        if (PQ.top() >= static_cast<long long>(K))
            return answer;
        answer++;
        long long val = PQ.top(); PQ.pop();
        val += PQ.top() * 2; PQ.pop();
        PQ.push(val);
    }
    if (PQ.top() >= K)
        return answer;
    return -1;
}

int main(void) {
}