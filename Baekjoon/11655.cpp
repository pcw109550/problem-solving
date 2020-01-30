#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    char *input; string s; getline(cin, s); input = (char *)s.c_str();
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == ' ' || (input[i] >= '0' && input[i] <= '9')) { continue; }
        if (input[i] >= 'a' && input[i] <= 'z') { input[i] = 'a' + (input[i] - 'a' + 13) % 26; }
        if (input[i] >= 'A' && input[i] <= 'Z') { input[i] = 'A' + (input[i] - 'A' + 13) % 26; }
    }
    printf("%s", input);
}