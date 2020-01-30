#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; int N; getline(cin, s); N = stoi(s);
    deque<int> deq;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        if (!s.compare(0, 10, "push_front")) {
            deq.push_front(atoi(s.c_str() + 11));
        } else if(!s.compare(0, 9, "push_back")) {
            deq.push_back(atoi(s.c_str() + 10));
        } else if(!s.compare(0, 9, "pop_front")) {
            if (deq.empty()) {cout << "-1\n"; }
            else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        } else if(!s.compare(0, 8, "pop_back")) {
            if (deq.empty()) { cout << "-1\n"; }
            else {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        } else if(!s.compare(0, 4, "size")) {
            cout << deq.size() << '\n';
        } else if(!s.compare(0, 5, "empty")) {
            cout << (deq.empty() == 1) << '\n';
        } else if(!s.compare(0, 5, "front")) {
            if (deq.empty()) {cout << "-1\n"; }
            else {
                cout << deq.front() << '\n';
            }     
        } else if(!s.compare(0, 4, "back")) {
            if (deq.empty()) { cout << "-1\n"; }
            else {
                cout << deq.back() << '\n';
            }
        }
    }
}