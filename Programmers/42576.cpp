#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> S;
    for (auto &name : completion)
        if (S.find(name) == S.end())
            S[name] = 1;
        else
            S[name]++;
    for (auto &name : participant)
        if (S.find(name) == S.end() || S[name] == 0)
            return name;
        else
            S[name]--;
    return answer;
}

int main(void) {   
}