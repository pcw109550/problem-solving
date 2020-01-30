#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    short array[26];
    fill(array, array + 26, 0);
    for (int i = 0; i < s.size(); i++) {
        array[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << array[i];
        if (i != 25)
            cout << " ";
    }
}