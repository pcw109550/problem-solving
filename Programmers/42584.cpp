#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer (prices.size(), 0);
    stack<pair<int, int> > S;
    for (int i = 0; i < prices.size(); i++) {
        while (!S.empty()) {
            auto top = S.top();
            if (top.first > prices[i]) {
                S.pop();
                answer[top.second] = i - top.second;
            } else
                break;
        }
        S.push({prices[i], i});
    }
    while (!S.empty()) {
        auto top = S.top(); S.pop();
        answer[top.second] = prices.size() - 1 - top.second;
    }
    return answer;
}

int main(void) {
}