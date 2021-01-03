#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> S, S2;
    for (auto phone_num : phone_book) {
        S2.insert(phone_num);
        for (int i = 1; i < phone_num.size(); i++)
            S.insert(phone_num.substr(0, i));
    }
    if (S2.size() != phone_book.size())
        return false;
    for (auto phone_num : phone_book) {
        if (S.find(phone_num) != S.end())
            return false;
    }
    return true;
}

int main(void) {
}