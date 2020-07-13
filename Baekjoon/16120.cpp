#include<bits/stdc++.h>
using namespace std;
enum State { START, EXIT, P1, P2, A1 };

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    // DFA
    State state = START;
    bool isPPAP = true;
    int accP = 0;
    for (auto c : s) {
        if (!isPPAP) { break; }
        switch (state) {
            case START:
                if (c == 'P') {
                    state = P1;
                    accP++;
                } else {
                    state = EXIT;
                }
                break;
            case EXIT:
                isPPAP = false;
                break;
            case P1:
                if (c == 'P') {
                    state = P2;
                    accP++;
                } else {
                    state = EXIT;
                }
                break;
            case P2:
                if (c == 'P') {
                    state = P2;
                    accP++;
                } else {
                    state = A1;
                }
                break;
            case A1:
                if (c == 'P') {
                    if (accP == 2) {
                        state = P1;
                    } else {
                        state = P2;
                    }
                    accP--;
                } else {
                    state = EXIT;
                }
                break;
            default:
                assert(false);
                break;
        }
    }
    cout << (isPPAP && accP == 1 && state == P1 ? "PPAP" : "NP");
}