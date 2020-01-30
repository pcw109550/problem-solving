#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input, idxstring, command;
    getline(cin, input);
    getline(cin, idxstring);
    
    int idx = atoi(idxstring.c_str());
    list<char> output(input.begin(), input.end());
    list<char>::iterator cursor = output.end();
    for (int i = 0; i < idx; i++) {
        getline(cin, command);
        if (!command.compare(0, 1, "L") && cursor != output.begin()){
            cursor--;
        } else if (!command.compare(0, 1, "D") && cursor != output.end()) {
            cursor++;
        } else if (!command.compare(0, 1, "B") && cursor != output.begin()) {
            cursor = output.erase(--cursor);
        } else if (!command.compare(0, 1, "P")){
            char ch = command.back();
            output.insert(cursor, ch);
        }
    }
    for (char c: output) {
        cout << c;
    }
}