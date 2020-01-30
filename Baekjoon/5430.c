#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int N; scanf("%d\n", &N);
    char command[100001] = {}; int arraylen;
    char dummy[16]; int start = 0, end = 0;
    int popcnt, revcnt, commandlen;
    for(int i = 0; i < N; i++) {
        start = end = revcnt = popcnt = commandlen = 0;
        arraylen = 0;
        scanf("%s\n", command);
        commandlen = strlen(command);
        scanf("%d\n", &arraylen);
        end = arraylen - 1;
        int array[arraylen];
        if (arraylen == 0) {
            scanf("%s[^\n]", dummy);
        } else if (arraylen == 1) {
            scanf("[%d]", &array[0]);
        } else {
            scanf("[%d,", &array[0]);
            for (int j = 1; j < arraylen - 1; j++) {
                scanf("%d,", &array[j]);
            }
            scanf("%d][^\n]", &array[arraylen - 1]);
        }
        for (int j = 0; j < commandlen; j++) {
            if (command[j] == 'R') { revcnt++; }
            if (command[j] == 'D') {
                popcnt++;
                if (revcnt % 2 == 0) { start++; } else { end--; }    
            }
            if (popcnt > arraylen) { printf("error\n"); break; }
        }
        if (popcnt > arraylen) { continue; }
        if (arraylen == 0) { printf("[]\n"); continue; }
        if (start > end) { printf("[]\n"); continue;}
        printf("[");
        if (revcnt % 2 == 0) {
            for (int j = start; j < end; j++) { printf("%d,", array[j]); }
            printf("%d]\n", array[end]);
        } else {
            for (int j = end; j > start; j--) { printf("%d,", array[j]); }
            printf("%d]\n", array[start]);
        }
    }
}