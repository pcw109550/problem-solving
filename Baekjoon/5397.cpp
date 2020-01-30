#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    int N = stoi(s);
    string input;
    for (int i = 0; i < N; i++) {
        getline(cin, input);
        list<char> output;
        list<char>::iterator idx = output.begin();
        for (char c: input) {
            if (c == '<' && idx != output.begin()) {
                idx--;
            } else if (c == '>' && idx != output.end()) {
                idx++;
            } else if (c == '-' && idx != output.begin()) {
                idx = output.erase(--idx);
            } else if (c != '<' && c != '>' && c != '-') {
                output.insert(idx, c);
            }
        }
        for (char c: output) {
            cout << c;
        }
        cout << "\n";
    }

}