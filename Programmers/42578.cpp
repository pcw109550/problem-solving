#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 1;
    unordered_map<string, vector<string> > M;
    for (auto cloth : clothes) {
        auto name = cloth[0];
        auto type = cloth[1];
        M[type].push_back(name);
    }
    for (auto it : M)
        answer *= it.second.size() + 1;
    answer -= 1;
    return answer;
}

int main(void) {
}