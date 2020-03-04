#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string temp; getline(cin, temp); string key;
    char *pt = (char *)temp.c_str(); cin >> key; // Vigenere Cipher
    // Can reduce space complexity by O(len(key)) but who cares
    int keylen = key.length(); string ct; 
    for (int i = 0; i < temp.length(); i++) {
        if (pt[i] == ' ') { ct += ' '; }
        else {
            ct += (pt[i] - key[i % key.length()] - 1 + 26) % 26 + 'a';
        }
    }
    cout << ct;
}