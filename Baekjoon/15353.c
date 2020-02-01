#include <stdio.h>
#include <string.h>
int main(void) {
    char a[10002] = {}, b[10002] = {}, result[10003] = {};
    scanf("%s %s", &a, &b); int al = strlen(a), bl = strlen(b);
    int max = al < bl ? bl : al; int carry = 0, temp; char c1, c2;
    for (int i = 0; i < max; i++) {
        if (al - 1 - i >= 0) { c1 = a[al - 1 - i]; } else { c1 = '0'; }
        if (bl - 1 - i >= 0) { c2 = b[bl - 1 - i]; } else { c2 = '0'; }
        temp = c1 + c2 - '0' * 2 + carry;
        if (temp > 9) { temp -= 10; carry = 1; } else { carry = 0; }
        result[i] = temp + '0';
    }
    if (carry) { result[max] = '1'; }
    for (int i = strlen(result) - 1; i >= 0; i--) { printf("%c", result[i]); }
}