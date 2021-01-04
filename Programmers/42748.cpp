#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;
    for (auto cmd : commands) {
        vector<int> temp = array;
        sort(temp.begin() + cmd[0] - 1, temp.begin() + cmd[1]);
        answer.emplace_back(temp[cmd[0] - 1 + cmd[2] - 1]);
    }
    return answer;
}

int main(void) {
}