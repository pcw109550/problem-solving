int main(void) {
    char a[1003] = {}, b[1003] = {};
    scanf("%s %s", &a, &b);
    int al = strlen(a), bl = strlen(b);
    int visited[1003] = {};
    int cnt = 0;
    for (int i = 0; i < al; i++) {
        for (int j = 0; j < bl; j++) {
            if (a[i] == b[j] && visited[j] == 0) {
                cnt++; visited[j] = 1; break;
            }
        }
    }
    printf("%d", al + bl - cnt * 2);
}